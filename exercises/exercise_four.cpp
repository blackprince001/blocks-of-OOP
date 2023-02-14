// rewrite the quiz class template described in the slides.
#include <any>
#include <iostream>
#include <string>
#include <vector>

template <typename OptionType>
class QuestionOption {
    OptionType option;
    bool is_correct;

   public:
    QuestionOption(OptionType answer, bool is_correct_option)
        : option(answer), is_correct(is_correct_option) {}

    OptionType get_option() { return option; }
};

class Question {
    std::string question_statement;
    std::vector<QuestionOption<std::any>> options;

   public:
    Question(std::string question) : question_statement(question){};
    void create_option(const std::any new_option, bool is_correct_option) {
        QuestionOption opt(new_option, is_correct_option);
        options.push_back(opt);
    }
    std::string get_question_statement() { return question_statement; }
    std::vector<QuestionOption<std::any>> get_options() { return options; }
};

class MakeQuiz {
    std::vector<Question> questions;

   public:
    void add_question(Question& quest) { questions.push_back(quest); }
    void show_questions() {
        for (auto& question : questions) {
            std::cout << question.get_question_statement() << "\n";
            for (auto option : question.get_options()) {
                // something happens here
                std::any caught = option.get_option();
                // std::cout << std::any(caught);  // cant print the options
                // because we cannot infer the type from this scope
            }
        }
    }
};

int main() {
    Question question1("What is the answer for the Question?");
    question1.create_option("std::string new_option", false);

    MakeQuiz quiz1;
    quiz1.add_question(question1);
    quiz1.show_questions();

    return 0;
}