#include<bits/stdc++.h>
using namespace std;

struct Ticket
{
    double price;
    int ticketsAvailable;
};
struct Event
{
    double xLocation;
    double yLocation;
    string description;
    vector<Ticket> tickets;
    int id;
};
vector<Event> allevents;

class CompareDist
{
public:
    bool operator()(pair<double,Event> n1,pair<double,Event> n2) {
        return n1.first>n2.first;
    }
};

bool comparePrices(Ticket e1,Ticket n2)
{
        return e1.price<n2.price;
};

double generateNumber(double low, double high)
{
    //l must be < than r
    if(low >= high)
        return 0.0;

    double diff = high-low;
    int inter = rand()% (int)diff;
    int inter2 = rand()% (int)diff;
    inter = (inter * inter2) % (int)diff;
    inter += low;

    int digits = 1;
    int divide = 10;
    while(inter2 / divide > 0)
    {
        divide *= 10;
        digits++;
    }
    double result = (double)inter + ((double)inter2/pow(10,digits));

    return result;
}
void generateEvents(int eventsCount, int ticketsCount)
{
    for(int i=0;i<eventsCount;++i)
    {
        Event event;
        event.xLocation = generateNumber(-10.00,10.00);
        event.yLocation = generateNumber(-10.00,10.00);
        event.id = allevents.size() + 1;
        for(int j=0; j<ticketsCount; ++j)
        {
            Ticket tick;
            tick.ticketsAvailable = (int)generateNumber(0,150);
            tick.price = generateNumber(1,1000);
            event.tickets.push_back(tick);
        }
        sort(event.tickets.begin(),event.tickets.end(),comparePrices);
        allevents.push_back(event);
    }

}
double getManhattanDist(Event e, double x, double y)
{
    double dist = 0;
    dist += abs(e.xLocation-x);
    dist += abs(e.yLocation-y);

    return dist;
}
void generateData()
{
    generateEvents(30,20);
}
void getAndSolveRequests()
{
    while(true)
    {
        cout << "Enter your coordinates or any character to exit:\n";
        double x = -999999,y = -999999;
        cin >> x;
        cin >> y;
        if(x == -999999 || y == -999999)
            break;

        priority_queue<pair<double,Event>, vector<pair<double,Event> >,CompareDist > ranking;
        for(int i=0; i<allevents.size(); ++i)
            ranking.push(make_pair(getManhattanDist(allevents[i],x,y),allevents[i]));

        cout << "The list of closest events to you is:\n";
        for(int i=0; i<5; ++i)
        {
            pair<double,Event> printhelper = ranking.top();
            ranking.pop();
            cout << "EVENT no." << printhelper.second.id << ", " << printhelper.first << " units away and costing $" << printhelper.second.tickets[0].price << "\n";
        }
        cout << "__________________________________\n\n\n\n\n";
    }
}

int main()
{
    generateData();
    getAndSolveRequests();
    return 0;
}
