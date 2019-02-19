#include "graphic_operations.h"

Rectangle::Rectangle(Point a, Point b){
  position_a = a;
  position_b = b;

}
Rectangle::Rectangle(Point a, double width, double height){
  position_a = a;
  position_b = Point(a.GetPositionX() + width, a.GetPositionY() + height);
}
void Rectangle::Translate(double x, double y){
  position_a = Point(position_a.GetPositionX() + x, position_a.GetPositionX() + y);
  position_b = Point(position_b.GetPositionX() + x, position_b.GetPositionX() + y);
}
void Rectangle::Resize(double r_x, double r_y){
  auto width = position_b.GetPositionX() - position_a.GetPositionX();
  auto height = position_b.GetPositionY() - position_a.GetPositionY();

  //Resize
  width = width * r_x;
  height = height * r_y;

  position_b = Point(position_a.GetPositionX() + width, position_a.GetPositionY() + height);
}
double Rectangle::Area(void){
  auto width = position_b.GetPositionX() - position_a.GetPositionX();
  auto height = position_b.GetPositionY() - position_a.GetPositionY();
  return width * height;
}
