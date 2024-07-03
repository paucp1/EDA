#include "Player.hh"
#include <map>
#include <stack>
#include <queue>


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Paukrbo


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
    
  typedef vector<int> VI;
  
  void ataca(int id, Pos act_pos) {
      for (int d = 0; d < 4; ++d) {
          Pos pos_aux = act_pos + Dir(d);
          if (pos_ok(pos_aux) and cell(pos_aux).unit_id != -1) {
                if (unit(cell(pos_aux).unit_id).player != me()) {
                    move(id, Dir(d));
                    return;
                }
            }
        }
    }
  
  void recull_mascara(int id, Pos act_pos) {
      for (int d = 0; d < 4; ++d) {
          Pos pos_aux = act_pos + Dir(d);
          if (pos_ok(pos_aux) and cell(pos_aux).mask) {
              move(id, Dir(d));
              return;
            }
        }
    }
  
  Pos bfs(Pos act_pos) {
      map<Pos, pair<int,Pos>> info;
      map<Pos, pair<int,Pos>>::iterator it;
      queue<Pos> Q;
      Q.push(act_pos);
      info.insert(make_pair(act_pos, make_pair(0, Pos(-1, -1))));
      
      while (not Q.empty()) {
          Pos p = Q.front();
          Q.pop();
          for (int i = 0; i < 4; ++i) {
                Pos p_aux = p + Dir(i);
                it = info.find(p_aux);
                if (it == info.end() and pos_ok(p_aux) and cell(p_aux).type != WALL) {
                    Q.push(p_aux);
                    int d = info[p].first + 1;
                    info.insert(make_pair(p_aux, make_pair(d, p)));
                }
          
                if (cell(p_aux).type == CITY or cell(p_aux).type == PATH) {
                    stack<Pos> cami;
                    cami.push(p_aux);
                    Pos p_pare = info[p_aux].second;
                    while (p_pare != Pos(-1, -1)) {
                        cami.push(p_pare);
                        p_pare = info[p_pare].second;
                    }   
                    cami.pop();
                    return cami.top();
                }
            }
        }
      return act_pos;
    }
              
          
          
  void ataca_city_path(int id, Pos act_pos) {
      Pos dist_min = bfs(act_pos);
      int i_new = dist_min.i;
      int j_new = dist_min.j;
      if (i_new == act_pos.i) {
          int res = j_new - act_pos.j;
          if (res > 0) move(id, Dir(1));
          else move(id, Dir(3));
        }
      
      else {
          int res = i_new - act_pos.i;
          if (res > 0) move(id, Dir(0));
          else move(id, Dir(2));
        }
    }
  
  void move_units() {
      VI my_u = my_units(me());
      int num_units = my_u.size();
      
      for (int i = 0; i < num_units; ++i) {
          int id = my_u[i];
          Unit u = unit(id);
          
          Pos act_pos = u.pos;
          
          ataca(id, act_pos);
          
          if (not u.mask and not u.immune) recull_mascara(id, act_pos);
          
          ataca_city_path(id, act_pos);
        }       
    }
  
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
      move_units();  
    }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
