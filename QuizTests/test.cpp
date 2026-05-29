#include "pch.h"
#include "Question.h"
#include "Quiz.h"

TEST(QuestionTest, CorrectAnswer) {
    Question q("2+2?", { "3", "4", "5" }, 1);

    EXPECT_TRUE(q.isCorrect(1));
    EXPECT_FALSE(q.isCorrect(0));
    EXPECT_FALSE(q.isCorrect(2));
}

TEST(QuizTest, AddAndSize) {
    Quiz quiz;

    quiz.addQuestion(Question("A?", { "1","2" }, 0));
    quiz.addQuestion(Question("B?", { "3","4" }, 1));

    EXPECT_EQ(quiz.size(), 2);
}

TEST(QuestionTest, TextCheck) {
    Question q("Hello?", { "Yes","No" }, 0);

    EXPECT_EQ(q.getText(), "Hello?");
}

TEST(QuestionTest, OptionsCount)
{
    Question q(
        "Столица Франции?",
        { "Берлин", "Париж", "Рим", "Лондон" },
        1
    );

    EXPECT_EQ(q.getOptions().size(), 4);
}

TEST(QuestionTest, FirstOptionCheck)
{
    Question q(
        "2 + 2?",
        { "3", "4", "5" },
        1
    );

    EXPECT_EQ(q.getOptions()[0], "3");
}

TEST(QuizTest, EmptyQuiz)
{
    Quiz quiz;

    EXPECT_EQ(quiz.size(), 0);
}