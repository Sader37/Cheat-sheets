// Abstract interfaces
class Shape {
public:
    virtual Point center() = 0;
    virtual void move(Point to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) const = 0;
    virtual ~Shape();
};