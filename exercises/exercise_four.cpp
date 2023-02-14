// rewrite the quiz class template described in the slides.
#include <iostream>
#include <string>
#include <vector>

template <typename OptionType>
class QuestionOption {
    OptionType option;
    bool is_correct;

   public:
    QuestionOption<OptionType>(OptionType answer, bool is_option_correct)
        : option(answer), is_correct(is_option_correct) {}

    OptionType get_option() { return option; }
};

template <typename T>
class Question {
    std::string question_statement;
    std::vector<QuestionOption<T>> options;

   public:
    Question(std::string question) : question_statement(question){};
    void add_option(QuestionOption<T> &opt) { options.push_back(opt); }
    std::string get_question_statement() { return question_statement; }
    std::vector<QuestionOption<T>> get_options() { return options; }
};

template <typename T>
class MakeQuiz {
    std::vector<Question<T>> questions;

   public:
    void add_question(Question<T> &quest) { questions.push_back(quest); }
    void show_questions() {
        for (auto question : questions) {
            std::cout << question.get_question_statement() << "\n";
            for (auto option : question.get_options()) {
                std::cout << option.get_option() << "\n";
            }
        }
    }
};

// Not the most efficient or elegant solution but this one works for the
// meantime.

int main() {
    Question<std::string> question1("What is the answer for the Question?");
    QuestionOption<std::string> first("Bananas", true);
    QuestionOption<std::string> second("1234", false);
    QuestionOption<std::string> third("2", false);
    QuestionOption<std::string> fourth("Coconut", false);

    question1.add_option(first);
    question1.add_option(second);
    question1.add_option(third);
    question1.add_option(fourth);

    MakeQuiz<std::string> quiz1;
    quiz1.add_question(question1);
    quiz1.show_questions();

    return 0;
}