#pragma once

class Move {
private:
    int* data;

public:
    void set_data_value(int d) {
        *data = d;
    }

    int get_data_value() {
        return *data;
    }

    Move(int d);
    Move(const Move& source);
    // NOTE Move constructor
    Move(Move&& source);
    ~Move();
};
