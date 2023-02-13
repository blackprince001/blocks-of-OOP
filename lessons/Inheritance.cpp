#include <iostream>

class BaseURL {
   public:
    BaseURL(std::string url, std::string custom)
        : link_destination(url), custom_url_replacement(custom) {}
    BaseURL()
        : link_destination("None"),
          custom_url_replacement(generate_random_admin_custom_url()) {}

    std::string get_link_destination() { return link_destination; }

    std::string get_custom_url_replacement() { return custom_url_replacement; }

   private:
    std::string link_destination;
    std::string custom_url_replacement;

    // some wack-ass validator for URLS
    std::string generate_random_admin_custom_url() {
        std::string alpha_lower = "abcdefghijklmnopqrstuvwxyz";

        int link_len = link_destination.length();
        if (link_len < 1) return "Not a valid link";

        std::string buf = "";
        for (int j = 0; j < 8; ++j) {
            buf += alpha_lower[alpha_lower.length() - (j * 2)];
        }
        return buf;
    }
};

class URL : public BaseURL {
   protected:
    bool is_active = true;
    unsigned int forward_count_freq = 0;

   public:
    // learnt this is how constructors are inherited in c++11 upwards
    // using scopes to copy all the constructors in this class
    // need to find out how this is done internally.
    using BaseURL::BaseURL;

    void link_clicked() { ++forward_count_freq; }
    void is_link_active() {
        if (is_active)
            std::cout << "Link not deleted. very active\n";
        else
            std::cout << "Link has been deactivated!\n";
    }
    void delete_link() { is_active = false; }
};

void test_with_constructor_parameters() {
    URL personal_website("www.prince.com", "prince-website");

    std::cout << personal_website.get_link_destination() << "\n";
    std::cout << personal_website.get_custom_url_replacement() << "\n";
    personal_website.is_link_active();
    personal_website.delete_link();
    personal_website.is_link_active();
}

void test_without_constructor_parameters() {
    URL personal_website;

    std::cout << personal_website.get_link_destination() << "\n";
    std::cout << personal_website.get_custom_url_replacement() << "\n";
    personal_website.is_link_active();
    personal_website.delete_link();
    personal_website.is_link_active();
}

int main() {
    test_with_constructor_parameters();
    test_without_constructor_parameters();
}