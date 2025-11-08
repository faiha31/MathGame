#include <iostream>
using namespace std;

enum enAnswer {RightAnswer=1,WrongAnswer=2};
enum enPassFail {Pass=1,Fail=2};
enum enQustionsLevel { Easy = 1, Med=2, Hard=3, Mixx=4 };
enum enQustionsType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix=5 };

struct stQuiz
{
    int NumberOfQuiz;
    enQustionsType QustionsType;
    enAnswer Answer;

};
struct stMathGame
{
    int NumberOfQuizess;
    enQustionsLevel QustionsLevel;
    enQustionsType QustionsType;
    int RightAnswer;
    int WrongAnswer;
    enPassFail FinalResult;
};
string NameFinalResult(enPassFail Result)
{
    string arrResult[2] = { "Pass :)","Fail :(" };
    return arrResult[Result - 1];

}
string NameQustionLevel(enQustionsLevel Level)
{
    string arrLevel[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrLevel[Level - 1];

}
string NameOperationType(enQustionsType OpType)
{
    string arrOP[5] = { "+", "-", "*","/", "Mix" };
    return arrOP[OpType - 1];

}
int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}
int QustionsLevel(enQustionsLevel QuizLevel)
{
    switch (QuizLevel)
    {
       case enQustionsLevel::Easy :
         return RandomNumber(1, 10);

       case enQustionsLevel::Med:
           return RandomNumber(1, 50);

       case enQustionsLevel::Hard:
           return RandomNumber(1, 100);

       case enQustionsLevel::Mixx:
           return QustionsLevel((enQustionsLevel)RandomNumber(1, 3));
    }

}
char OperationType (enQustionsType QustionsType)
{
    switch (QustionsType)
    {
    case enQustionsType::Add:
        return '+';
    case enQustionsType::Sub:
        return '-';
    case enQustionsType::Mul:
        return '*';
    case enQustionsType::Div:
        return '/';
    case enQustionsType::Mix:
        return OperationType((enQustionsType)RandomNumber(1, 4));


    }

}
enQustionsLevel GetRandomLevel(enQustionsLevel InitialLevel)
{
    if (InitialLevel != enQustionsLevel::Mixx)
        return InitialLevel;

    return (enQustionsLevel)RandomNumber(1, 3);
}

enQustionsType GetRandomType(enQustionsType InitialType)
{
    if (InitialType != enQustionsType::Mix)
        return InitialType;

    return (enQustionsType)RandomNumber(1, 4);
}

void PrintQustionsAnswer(enAnswer Answers, int Result)
{
    if (Answers == enAnswer::RightAnswer)
        cout << "Right Answer :) " << endl;
    else
    {
        cout << "Wrong Answer :( " << endl;
        cout << "The right answer is : " << Result<<endl;
    }

}
int AnswerUser(enQustionsType OP, int FirstNumber, int SecondNumber)
{
   
    int Answer;

    cout << FirstNumber << endl << SecondNumber << " " << NameOperationType(OP) << endl;
    cout << "-------------" << endl;
    cin >> Answer;

    return Answer;

}
int EvaluateMathOp(enQustionsType OP ,int FirstNumber, int SecondNumber)
{
   
    int ActualResult=0;


    switch (OP)
    {
       case enQustionsType::Add:
       {
           ActualResult = FirstNumber + SecondNumber;
           return ActualResult;
       
       }
       case enQustionsType::Sub:
       {
           ActualResult = FirstNumber - SecondNumber;
           return ActualResult;
       
       }
       case enQustionsType::Mul:
       {
           ActualResult = FirstNumber * SecondNumber;
           return ActualResult;
       
       
       }
       case enQustionsType::Div:
       {
           ActualResult = FirstNumber / SecondNumber;
           return ActualResult;
       
       }
       
    }
          
}
void SetWinnerScreenColor(enAnswer Answer)
{

    switch (Answer)
    {
    case enAnswer::RightAnswer:
        system("Color 2F"); // Green background 
        break;

    case enAnswer::WrongAnswer:
        system("Color 4F"); // Red background 
        cout << "\a";
        break;;
    }
}
void PrintFinalResultScreen(enPassFail Result)
{
    cout << "\n\n_________________________________________________________" << endl;
    cout << "Final Results is " << NameFinalResult(Result) << endl;
    cout << "_________________________________________________________" << endl;
}
stMathGame FillMathGame (int NumberOfQu, enQustionsLevel  QuLevel, enQustionsType OPType, int NumOfRightAns, int NumOfWrongAns)
{
    stMathGame MathGame;

    MathGame.NumberOfQuizess = NumberOfQu;

    MathGame.QustionsLevel = QuLevel;
    MathGame.QustionsType = OPType;

    MathGame.RightAnswer = NumOfRightAns;
    MathGame.WrongAnswer = NumOfWrongAns;


    if (NumOfRightAns > NumOfWrongAns)
        MathGame.FinalResult = enPassFail::Pass;
    else
        MathGame.FinalResult = enPassFail::Fail;

    return MathGame;
    

}
void PrintFinalResultGame(stMathGame MathGame)
{
    cout << "Number of Questions : "<< MathGame.NumberOfQuizess << endl;
    cout << "Questions Level : " << NameQustionLevel( MathGame.QustionsLevel) << endl;
    cout << "OP Type : " << NameOperationType(MathGame.QustionsType) << endl;
    cout << "Number of right answer : " << MathGame.RightAnswer << endl;
    cout << "Number of wrong answer : " << MathGame.WrongAnswer << endl;



}
int ReadHowManyQustions()
{
    int Number;

       do
        {
           cout << "How manu questions do you want to answers ? ";
               cin >> Number;

       } while (Number < 0);

    return Number;

}
stMathGame PlayGame(int HowManyQu)
{
    stQuiz Quizess;

    int RightAnswer=0, WrongAnswer=0, LevelChoice=0, TypeChoice=0,AnswerQu=0;

    enQustionsLevel QuLevel;
    enQustionsType QuType;

    enAnswer Answer;
    enPassFail FinalResult;

    cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
    cin >> LevelChoice;

    cout << "Enter Question Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
    cin >> TypeChoice;

    QuLevel = (enQustionsLevel)LevelChoice;
    QuType = (enQustionsType)TypeChoice;

   
    for (int NumOfQuizess = 1; NumOfQuizess <= HowManyQu; NumOfQuizess++)
    {
        cout << "\nQuestion [1/" << NumOfQuizess << "]" << endl;

        enQustionsLevel CurrentLevel = GetRandomLevel(QuLevel);
        enQustionsType CurrentType = GetRandomType(QuType);

        int FirstNumber = QustionsLevel(CurrentLevel);
        int SecondNumber = QustionsLevel(CurrentLevel);

        int ResultOfUser = AnswerUser(CurrentType, FirstNumber, SecondNumber);
        int ActualResult = EvaluateMathOp(CurrentType, FirstNumber, SecondNumber);

        if (ResultOfUser == ActualResult)
        {
            RightAnswer++;
            Quizess.Answer = enAnswer::RightAnswer;
        }
        else
        {
            WrongAnswer++;
            Quizess.Answer = enAnswer::WrongAnswer;
        }

        PrintQustionsAnswer(Quizess.Answer, ActualResult);
        SetWinnerScreenColor(Quizess.Answer);
    }
    

   return FillMathGame(HowManyQu, QuLevel, QuType, RightAnswer, WrongAnswer);

}

void ResetScreen()
{
    system("cls");
    system("Color 0F"); // Black background and White text

}
void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();

        stMathGame MathGame = PlayGame(ReadHowManyQustions());
        PrintFinalResultScreen(MathGame.FinalResult);

        PrintFinalResultGame(MathGame);

        cout << endl  << "Do you want to play again ? Y/N ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}
int main()
{
    srand((unsigned int)time(NULL));

    StartGame();

    return 0;
}

