#include "MarkerManager.hpp"
#include <iostream>
#include <algorithm>

bool MarkerManager::contains(int id) const
{
    for (const Marker& marker : markers)
    {
        if (marker.id==id)
        {
            return true;
        }
    }
    return false;
}

bool MarkerManager::add(const Marker& marker)
{
    if (marker.id<=0)
    {
        return false;
    }

    if(marker.priority<0 || marker.priority>100)
    {
        return false;
    }

    if(contains(marker.id))
    {
        return false;
    }

    markers.push_back(marker);

    return true;
}

void MarkerManager::displayAll() const
{
    for (const Marker& marker : markers)
    {
        std::cout<<"bianhao"<<marker.id
                 <<",weizhi:("
                 <<marker.x_mm<<","
                 <<marker.y_mm<<")"
                 <<",youxianji"
                 <<marker.priority
                 <<'\n';
        
    }
}

int MarkerManager::countByPriority(int threshold) const
{
    int count=0;

    for (const Marker& marker : markers)
    {
        if (marker.priority>=threshold)
        {
            count++;
        }
    }

    return count;
}

bool MarkerManager::updatePriority(int id,int newPriority)
{
    if (newPriority<0 || newPriority>100)
    {
        return false;
    }

    for (Marker& marker:markers)
    {
        if (marker.id==id)
        {
            marker.priority=newPriority;
            return true;
        }
    }
    return false;

}

void MarkerManager::sortByPriority()
{
    std::sort(markers.begin(),markers.end(),
              [](const Marker& a,const Marker& b)
    {
        if (a.priority != b.priority)
        {
            return a.priority >b.priority;
        }
        return a.id < b.id;

    }
    );
}