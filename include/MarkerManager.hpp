#ifndef MARKERMANAGER_HPP
#define MARKERMANAGER_HPP

#include <vector>

struct Marker
{
    int id;
    double x_mm;
    double y_mm;
    int priority;
};


class MarkerManager
{
    private:
    std::vector<Marker> markers;
    public:
    bool add(const Marker& marker);
    bool contains(int id) const;
    void displayAll() const;
    int countByPriority(int threshold) const;
    bool updatePriority(int id,int newPriority);
    void sortByPriority();
};

#endif