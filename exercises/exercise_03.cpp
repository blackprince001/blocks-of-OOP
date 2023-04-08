// rewrite the quiz class template described in the slides.
#include <iostream>
#include <string>
#include <vector>

struct QuestionOption {
  std::string option;
  bool is_correct;

 public:
  QuestionOption(std::string answer, bool is_correct_option)
      : option(answer), is_correct(is_correct_option) {}

  std::string get_option() { return option; }
};

class Question {
  std::string question_statement;
  std::vector<QuestionOption> options;

 public:
  Question(std::string question) : question_statement(question){};
  void create_option(std::string new_option, bool is_correct_option) {
    QuestionOption opt(new_option, is_correct_option);
    options.push_back(opt);
  }
  std::string get_question_statement() { return question_statement; }
  std::vector<QuestionOption> get_options() { return options; }
};

class MakeQuiz {
  std::vector<Question> questions;

 public:
  void add_question(Question &quest) { questions.push_back(quest); }
  friend std::ostream &operator<<(std::ostream &out, MakeQuiz quiz) {
    for (auto &question : quiz.questions) {
      out << question.get_question_statement() << "\n";
      for (auto option : question.get_options())
        out << option.get_option() << "\n";
    }
    return out;
  }
};

int main() {
  Question question1("What is the answer for the Question?");
  question1.create_option("string", false);
  question1.create_option("23", false);
  question1.create_option("411.2f", false);

  Question question2("What is the answer for the Question?");
  question2.create_option("string", false);
  question2.create_option("23", false);
  question2.create_option("411.2f", false);

  Question question3("What is the answer for the Question?");
  question3.create_option("string", false);
  question3.create_option("23", false);
  question3.create_option("411.2f", false);

  MakeQuiz quiz1;
  quiz1.add_question(question1);
  quiz1.add_question(question2);
  quiz1.add_question(question3);
  std::cout << quiz1;

  return 0;
}