#include <iostream>
#include <vector>

using std::string;
using std::vector;

class User {
  string Name;
  string UUId;

 public:
  User(string name, string user_id) : Name(name), UUId(user_id) {}
  string get_username() { return Name; }
};

class YoutubeChannel {
 private:
  string channelName;
  string ownerName;
  vector<string> publishedVideoTitles;
  unsigned int subscriberCount;

 public:
  YoutubeChannel(string YoutubeChannelName, User Owner)
      : channelName(YoutubeChannelName),
        ownerName(Owner.get_username()),
        subscriberCount(0) {}
  string getOwnerName() { return ownerName; }
  string getChannelName() { return channelName; }
  void changeChannelName(string newChannelName) {
    channelName = "";
    channelName += newChannelName;
  }
  void subscribe() { subscriberCount += 1; };
  void unSubscribe() { subscriberCount -= 1; };
  int getSubscriberCount() { return subscriberCount; }
  void publishVideo(string VideoTitle) {
    publishedVideoTitles.push_back(VideoTitle);
  }
  void getInfo() {
    std::cout << "This channel is owned by: " << getOwnerName() << "\n";
    std::cout << "Channel Name: " << getChannelName() << "\n";
    std::cout << "Number of Subscribers: " << getSubscriberCount() << "\n";
    std::cout << "List of Videos Published!\n";
    for (auto video : publishedVideoTitles) std::cout << "-" << video << "\n";
  }
};

void test_YoutubeChannelClass() {
  User usr1("Theresa", "1241223");
  YoutubeChannel ytChannel("Theresa CPP", usr1);

  ytChannel.getInfo();
  ytChannel.publishVideo("Learning how to write Classes with CPP");
  for (int i = 0; i < 20; ++i) ytChannel.subscribe();

  ytChannel.getInfo();
}

int main() {
  test_YoutubeChannelClass();
  return 0;
}