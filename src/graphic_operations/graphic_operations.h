
class Point {
 public:
  Point(double x, double y): position_x(x), position_y(y){};
  double GetPositionX(void){return position_x;};
  double GetPositionY(void){return position_y;};
 private:
  double position_x, position_y;
};

class Rectangle {
 public:
  Rectangle(Point a, Point b);
  Rectangle(Point a, double width, double height);
  void Translate(double x, double y);
  void Resize(double r_x, double r_y);
  double Area(void);
 private:
  Point position_a;
  Point position_b;
};