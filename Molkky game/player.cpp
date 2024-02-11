#include "player.hh"
#include <iostream>

Player::Player(const std::string& player):
    player_(player)
{
   Player::score = 0;
// additional logic Date today(5, 5, 2020); day = 5, month = 5 and year = 2020
}
void Player::add_points(int pts){
    if(Player::score<50){
            Player::score += pts;
   }
}
std::string Player::get_name(){
    return player_;
}
int Player::get_points(){
    return Player::score;
}
bool Player::has_won(){
    if(Player::score==50){
return true;
}
    else if(Player::score>50){
        std::cout<< Player::player_<<" gets penalty points!"<<std::endl;
        Player::score = 25; // penalty points

}
return false;}
