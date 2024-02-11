#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

#endif // PLAYER_HH

class Player
{
public:
        Player(const std::string& author);
        // all methods
        std::string get_name();
        int get_points();
        bool has_won();
        void add_points(int pts);


private:
        std::string player_;
        int score;



};
