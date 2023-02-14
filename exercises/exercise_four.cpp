// rewrite the quiz class template described in the slides.
#include <any>
#include <iostream>
#include <string>
#include <vector>

class QuestionOption {
    std::any option;
    bool is_correct;

   public:
    QuestionOption(void* answer, bool is_correct_option)
        : option(answer), is_correct(is_correct_option) {}

    std::any get_option() { return option; }
};

class Question {
    std::string question_statement;
    std::vector<QuestionOption> options;

   public:
    Question(std::string question) : question_statement(question){};
    void create_option(std::string new_option, bool is_correct_option) {
        QuestionOption opt(&new_option, is_correct_option);
        options.push_back(opt);
    }
    std::string get_question_statement() { return question_statement; }
    std::vector<QuestionOption> get_options() { return options; }
};

class MakeQuiz {
    std::vector<Question> questions;

   public:
    void add_question(Question& quest) { questions.push_back(quest); }
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
    Question question1("What is the answer for the Question?");
    question1.create_option("std::string new_option", false);

    MakeQuiz quiz1;
    quiz1.add_question(question1);
    quiz1.show_questions();

    return 0;
}