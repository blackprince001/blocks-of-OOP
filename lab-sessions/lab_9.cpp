// Fix the code below to print the desired input using operator overloading
#include <iostream>
#include <string>

using namespace std;

class YouTubeChannel {
   public:
    string Name;
    int SubscribersCount;
    YouTubeChannel(string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }
    // Insert your code here
    friend ostream& operator<<(ostream& os, const YouTubeChannel& yt) {
        os << "Channel Name: " << yt.Name
           << "\nNumber of Subscribers: " << yt.SubscribersCount;
        return os;
    }
};

int main() {
    YouTubeChannel yt1 = YouTubeChannel("Grade A Under A", 3680000);
    cout << yt1;
    return 0;
}