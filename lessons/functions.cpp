#include <iostream>

void replchar(const char chin, int ntimes) {
    for (int i = 0; i < ntimes; ++i) std::cout << chin;
}

struct Distance {
    double x;
    double y;

    // Constructor overloading
    // since we load overloading everything in cpp
    // we can overload constructors; and in this example
    // we overload the Distance constructor to take values when there are some
    // and ZEROS when there are None;
    Distance() : x(0), y(0) {}
    Distance(double x, double y) : x(x), y(y) {}
};

Distance NullDistance;  // Reference objects are made global so that you can
                        // perform function pointers with them
// as seen in line 40

Distance add_distances(Distance &pos_1, Distance &pos_2) {
    Distance ref;
    // whatever weird math that is going on here!
    ref.x = (pos_1.x + pos_2.x);
    ref.y = (pos_1.y + pos_2.y);

    return ref;
}

inline double area_of_circle(double radius) {
    return (3.14159 * (radius * radius));
}

double magnitude_from_origin(Distance ref) {
    return (ref.x * ref.x) + (ref.y * ref.y);
}

Distance &reset_distance() {
    return NullDistance;  // references whatever values NullDistance has
}

Distance change_cordinates(
    Distance &ref);  // we can change the values of the ref
Distance dont_change_cordinates(
    const Distance
        &ref);  // the function literally becomes a read only function
// no modification of the Distance object referenced

int operation(int x, int y, int (*Callable)(int, int)) {
    // pointer functions as arguments
    return Callable(x, y);
}

int addition(int a, int b) { return a + b; }

int main() {
    // pass by value
    replchar('*', 45);

    char dash = '-';
    int nloops = 15;

    // pass by value but with variables
    replchar(dash, nloops);

    // is the backslash a character? Yes!
    replchar('\n', 20);  // Printing a lot of empty spaces

    Distance kyei_location(12.31, 13.8);
    std::cout << "Resultant: " << magnitude_from_origin(kyei_location);

    Distance KK_location(24, 25);
    Distance Resultant =
        add_distances(kyei_location, KK_location);  // pass by reference
    std::cout << "Resultant: " << magnitude_from_origin(Resultant);

    Distance origin;

    Distance origin_to_kyei = add_distances(kyei_location, origin);
    std::cout << "Resultant: "
              << magnitude_from_origin(
                     origin_to_kyei);  // should be basically finding the value
                                       // for the mag of Kyei

    kyei_location = reset_distance();  // we reference the NullDistance values
                                       // to kyei_location
    // this also means we can alter the values of NullDistance when we move it
    // to the lHS. `reset_distance = some distance object with valid values;`
    std::cout << "Resultant: " << magnitude_from_origin(kyei_location);

    int res = operation(12, 45, addition);
    std::cout << res;

    return 0;
}