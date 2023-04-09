// Design using UML an application that lets users send and receive messages
// from other users of the same application
#include <bits/types/time_t.h>
#include <time.h>

#include <iostream>
#include <ostream>
#include <vector>

// Explanation of the UML Diagram:
// The main components of the messaging application are the User, Message, and
// Chat classes. The User class represents a user of the messaging application.
// It contains attributes such as username, password, and contact list. The
// contact list is a list of other User objects that the user is friends with.
// The Message class represents a message that is sent between two users. It
// contains attributes such as the sender, receiver, content, and timestamp. The
// Chat class represents a conversation between two users. It contains a list of
// Message objects that have been sent between the two users. The User class has
// a composition relationship with the Chat class. This means that each User
// object owns a Chat object that represents their conversation with another
// user. The User class has an aggregation relationship with the Message class.
// This means that each User object can have many Message objects associated
// with it. The Chat class has an aggregation relationship with the Message
// class. This means that each Chat object can have many Message objects
// associated with it. The User class also has association relationships with
// other User objects, representing the user's contact list. This allows a user
// to send messages to their friends. The MessagingSystem class is a singleton
// class that represents the overall messaging system. It contains a list of all
// User objects in the system and provides methods for adding and removing
// users, as well as searching for users by username.

class User {
 public:
  User(std::string name, std::string passwd)
      : name(name), password(passwd), contact_list({}) {}
  std::string get_name() const { return name; }

 private:
  std::string name;
  std::string password;
  std::vector<User> contact_list;
};

class Message {
 public:
  Message(User host, User receiver, std::string message)
      : sender(host),
        receiver(receiver),
        message(message),
        timestamp(time(NULL)) {}

  friend std::ostream& operator<<(std::ostream& out, Message& current_message) {
    out << "From: " << current_message.sender.get_name();
    out << "\nTo: " << current_message.receiver.get_name();
    out << "\nMessage: " << current_message.message;
    out << "\nTime sent: " << asctime(gmtime(&current_message.timestamp));
    return out;
  }

 private:
  User sender;
  User receiver;
  std::string message;
  time_t timestamp;
};

class Chat {
 public:
  Chat() : conversation_list({}) {}
  void auto_add(const Message messageSent) {
    conversation_list.push_back(messageSent);
  }
  friend std::ostream& operator<<(std::ostream& out, Chat chatbox) {
    for (auto conversation : chatbox.conversation_list) {
      out << conversation << "\n\n";
    }
    return out;
  }

 private:
  std::vector<Message> conversation_list;
};

int main() {
  Chat PrinceErnestChatBox;
  User prince("Prince", "ABCDEF");
  User ernest("Ernest", "ABCDEF");
  Message newMessage1(prince, ernest, "Hello Bro!");

  Message newMessage2(ernest, prince, "Hello Prince!");

  Message newMessage3(prince, ernest, "Hope sey you do the assignment Bro!");

  PrinceErnestChatBox.auto_add(newMessage1);
  PrinceErnestChatBox.auto_add(newMessage2);
  PrinceErnestChatBox.auto_add(newMessage3);

  std::cout << PrinceErnestChatBox;
}