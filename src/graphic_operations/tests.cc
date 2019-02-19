#include "gtest/gtest.h"
#include "graphic_operations.h"

TEST(PointOperations, PointCreation) {
    Point p(4, 5);
    ASSERT_EQ(4, p.GetPositionX());
    ASSERT_EQ(5, p.GetPositionY());
}

TEST(RectangleOperations, RectangleCreation) {
    Rectangle r(Point(0,0), Point(10, 10));
    ASSERT_EQ(100, r.Area());
}

TEST(RectangleOperations, RectangleResize) {
    Rectangle r(Point(0,0), Point(10, 10));
    r.Resize(2, 2);
    ASSERT_EQ(400, r.Area());
}

TEST(RectangleOperations, RectangleTranslate) {
    Rectangle r(Point(0,0), Point(10, 10));
    r.Translate(53, 56);
    ASSERT_EQ(100, r.Area());
}