// Friend function example for class
class Friend {
private:
    int val = 0;
    friend ostream& operator<<(ostream& out, const FriendEx& o);
};
ostream& operator<<(ostream& out, const FriendEx& o) {
    return out << o.val;
}
//Friend c;
//std::cout << c;

// Perhaps the most common use case for friend functions is overloading << and >> for I/O
