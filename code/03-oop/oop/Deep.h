#pragma once

class Deep {
private:
    int* data;

public:
    void set_data_value(int d) {
        *data = d;
    }

    int get_data_value() {
        return *data;
    }

    Deep(int d);
    Deep(const Deep& source);
    ~Deep();
};
