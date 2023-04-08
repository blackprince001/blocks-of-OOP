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
  friend std::ostream& operator<<(std::ostream& out, YoutubeChannel& channel) {
    out << "This channel is owned by: " << channel.getOwnerName() << "\n";
    out << "Channel Name: " << channel.getChannelName() << "\n";
    out << "Number of Subscribers: " << channel.getSubscriberCount() << "\n";
    out << "List of Videos Published!\n";
    for (auto video : channel.publishedVideoTitles) out << "-" << video << "\n";
    return out;
  }
};

void test_YoutubeChannelClass() {
  User usr1("Theresa", "1241223");
  YoutubeChannel ytChannel("Theresa CPP", usr1);

  std::cout << ytChannel;
  ytChannel.publishVideo("Learning how to write Classes with CPP");
  for (int i = 0; i < 20; ++i) ytChannel.subscribe();

  std::cout << ytChannel;
}

int main() {
  test_YoutubeChannelClass();
  return 0;
}