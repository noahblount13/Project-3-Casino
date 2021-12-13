/*
Noah Blount the Tall Joe @ "Art Joe"
Part of the Joe Bros
Project 3 casino yeet
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime> //including things cause stuff
#include <cstdlib> 
#include <limits>
using namespace std;

//###############################################################################################

/*void sampleGame(int &currentBalance)
{
  char continueYOrN;
  int betAmount;
  bool win;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    betAmount = correctIntInput(betAmount);
    betAmount = validBet(currentBalance, betAmount);
    
    [INSERT GAME CODE HERE]

    if (win)
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, [PAYOUT], betAmount, true);
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, [PAYOUT], betAmount, false);
      cout << "Your new balance is " << currentBalance << "\n";
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n";
      break;
    }

    cout << "Would you like to play again?\n";
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN);

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y')
    {
      cout << "Invalid input, please enter a new input:\n";
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}*/

//###############################################################################################

int randomWithMax(int maximum)
{
  int random;
  random = rand() % (maximum + 1); //function that produces a random number between 0 and maximum
  return random;
}

//###############################################################################################

void updateBalance(int &curBal, int payoff, int amountBet, bool didWin)
{
  if (didWin)
  {
    curBal = curBal + payoff * amountBet; //win formula
  }
  else
  {
    curBal -= amountBet; //lose formula
  }

  if (curBal < 0)
  {
    curBal = 0; //ensure balance never goes below zero
  }
}

//###############################################################################################

char correctCharInput(char input)
{
  while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ensure invalid char inputs dont break program
      cout << "Invalid input, please enter a valid input:\n";
      cin >> input;
    }
    return input;
}

//###############################################################################################

int correctIntInput(int input)
{
  while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ensure invalid intinputs dont break program
      cout << "Invalid input, please enter a valid input:\n";
      cin >> input;
    }
    return input;
}

//###############################################################################################

int validBet(int bal, int bet)
{
  while (bet > bal || bet <=0) //keeps looping until a valid bet is entered
  {
    while (bet > bal) // ensure you cant bet more than you have
    {
      cout << "You don't have that much money! Please input a new bet amount:\n$";
      cin >> bet;
      bet = correctIntInput(bet);
    }
    while (bet <= 0) //ensure you cant bet a negative value, or bet nothing
    {
      cout << "You need to bet more than that! Please input a new bet amount:\n$";
      cin >> bet;
      bet = correctIntInput(bet);
    }
  }
  return bet;
}

//###############################################################################################

void twoUp(int &currentBalance)
{
  char continueYOrN;
  char hOrT;
  char oddHeadOrTail;
  int betAmount;
  int coinOne; //declaring vars to use later
  int coinTwo;
  int payout;
  int count;
  bool win;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    betAmount = correctIntInput(betAmount); //display and validate balance and bet amount
    betAmount = validBet(currentBalance, betAmount);
    
    cout << "Come in spinner!\n";
    cout << "Do you bet on heads or tails?\n"; //get users bet
    cin >> hOrT;
    hOrT = correctCharInput(hOrT);

    while (!(hOrT == 't' || hOrT == 'T' || hOrT == 'h' || hOrT == 'H')) //validate user input
    {
      cout << "Invalid input, please enter 'H' or 'T'\n";
      cin >> hOrT;
      hOrT = correctCharInput(hOrT);
    }

    cout << "You flip the two coins...\n";
    coinOne = randomWithMax(1); //0 is heads, 1 is tails
    coinTwo = randomWithMax(1);

    if (coinOne == 0)
    {
      cout << "Coin one landed on heads\n"; //print coin values
    }
    else if (coinOne == 1)
    {
      cout << "Coin one landed on tails\n";
    }

    if (coinTwo == 0)
    {
      cout << "Coin two landed on heads\n";
    }
    else if (coinTwo == 1)
    {
      cout << "Coin two landed on tails\n";
    }

    oddHeadOrTail = coinOne + coinTwo; //if both heads, 0; if both tails, 2; if odds, 1
    count = 0;

    while (oddHeadOrTail == 1 && count < 5)
    {
      cout << "You spun odds!\n"; //when odds spun, keep spinning until user wins
      count += 1;

      if (count >= 5)
      {
        cout << "You Odded out!"; //user odds out
        break;
      }

      cout << "To flip again, press enter\n";
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear entirety of input to allow user pause
      cin.get();
      cout << "You flip the two coins again...\n";
      coinOne = randomWithMax(1); //0 is heads, 1 is tails
      coinTwo = randomWithMax(1);

      if (coinOne == 0)
      {
        cout << "Coin one landed on heads\n"; //print coin values
      }
      else if (coinOne == 1)
      {
        cout << "Coin one landed on tails\n";
      }

      if (coinTwo == 0)
      {
        cout << "Coin two landed on heads\n";
      }
      else if (coinTwo == 1)
      {
        cout << "Coin two landed on tails\n";
      }

      oddHeadOrTail = coinOne + coinTwo; //if both heads, 0; if both tails, 2; if odds, 1
    }

    if (count >= 5)
    {
      count = 0;
      win = true; //win on odding out
      payout = 28;
    }

    else if (((hOrT == 'h' || hOrT == 'H') && oddHeadOrTail == 2) || ((hOrT == 't' || hOrT == 'T') && oddHeadOrTail == 0))
    {
      win = false;
      payout = 1; //loss on bad bet
    }
    else if (((hOrT == 'h' || hOrT == 'H') && oddHeadOrTail == 0) || ((hOrT == 't' || hOrT == 'T') && oddHeadOrTail == 2))
    {
      win = true;
      payout = 1; //win on good bet
    }
    

    if (win)
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, payout, betAmount, true); //print user won and update users balance
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, payout, betAmount, false); //print user lsot and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n"; //kick bankrupt player out
      break;
    }

    cout << "Would you like to play again?\n"; //ask user to play agian
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN);

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y') //validate continue user input
    {
      cout << "Invalid input, please enter a new input:\n";
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}

//###############################################################################################

void twentyOne(int &currentBalance)
{
  int userNumOne;
  int userNumTwo;
  int userHitTemp;
  int compScore;
  int userScore;
  int betAmount;
  char hitOrStay; //declare variables for later use
  char continueYOrN;
  char aceYOrN;
  bool win;
  bool firstCardAce;
  bool secondCardAce;
  bool tempCardAce;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    compScore = randomWithMax(8) + 16;
    betAmount = correctIntInput(betAmount);
    betAmount = validBet(currentBalance, betAmount); //show current balance and validate bet
    hitOrStay  = 'h';
  
    userNumOne = randomWithMax(12)+1; //assign first card value

    if (userNumOne > 10)
    {
      userNumOne = 10; //kings, queens, and jacks are worth ten points
    }

    if (userNumOne > 1)
    {
      cout << "Your first card is " << userNumOne << " points.\n"; //if card is not ace display its value
      firstCardAce = false;
    }
    else
    {
      cout << "Your first card is an ace.\n"; //if card is ace set val to true to run code later
      firstCardAce = true;
    }

    userNumTwo = randomWithMax(12)+1; //create second card value

    if (userNumTwo > 10)
    {
      userNumTwo = 10; //kings, queens, and jacks are worth ten points
    }

    if (userNumTwo > 1)
    {
      cout << "Your second card is " << userNumTwo << " points.\n"; //if card is not ace display its value
      secondCardAce = false;
    }
    else
    {
      cout << "Your second card is an ace.\n"; //if card is ace set bool to true to run code later
      secondCardAce = true;
    }

    if (firstCardAce)
    {
      cout << "Would you like your first ace to equal 11? (Otherwise, it will equal a 1)\n"; //ask user if ace should be worth 1 or 11 points
      cin >> aceYOrN;
      aceYOrN = correctCharInput(aceYOrN);

      while (aceYOrN != 'n' && aceYOrN != 'N' && aceYOrN != 'y' && aceYOrN != 'Y') //validate user input for if they want the ace to equal 1 or 11
      {
        cout << "Invalid input, please enter a new input:\n";
        cin >> aceYOrN;
        aceYOrN = correctCharInput(aceYOrN);
      }

      if (aceYOrN == 'Y' || aceYOrN == 'y') //set ace to 11 points
      {
        userNumOne = 11;
      }
      else if (aceYOrN == 'N' || aceYOrN == 'n') //set ace to one point
      {
        userNumOne = 1;
      }

    }

    if (secondCardAce)
    {
      cout << "Would you like your second ace to equal 11? (Otherwise, it will equal a 1)\n"; //ask user if ace should be worth 1 or 11 points
      cin >> aceYOrN;
      aceYOrN = correctCharInput(aceYOrN);

      while (aceYOrN != 'n' && aceYOrN != 'N' && aceYOrN != 'y' && aceYOrN != 'Y') //validate user input
      {
        cout << "Invalid input, please enter a new input:\n";
        cin >> aceYOrN;
        aceYOrN = correctCharInput(aceYOrN);
      }

      if (aceYOrN == 'Y' || aceYOrN == 'y') //set ace to 11 points
      {
        userNumTwo = 11;
      }
      else if (aceYOrN == 'N' || aceYOrN == 'n') //set ace to 1 point
      {
        userNumTwo = 1;
      }
    }

    userScore = userNumOne + userNumTwo;
    cout << "Your current point total is " << userScore << " points.\n"; //display users current points

    while (userScore < 21 && (hitOrStay == 'h' || hitOrStay == 'H')) //run until user busts or decides to stay
    {
      cout << "Would you like to (h)it or (s)tay?\n"; //ask user if they want to hit or stay
      cin >> hitOrStay;
      hitOrStay = correctCharInput(hitOrStay);

      while (hitOrStay != 'h' && hitOrStay != 'H' && hitOrStay != 's' && hitOrStay != 'S') //validate user input
      {
        cout << "Invalid input, please enter a new input:\n";
        cin >> hitOrStay;
        hitOrStay = correctCharInput(aceYOrN);
      }

      if (hitOrStay == 'h' || hitOrStay == 'H') //if user hits
      { 
        userHitTemp = randomWithMax(12)+1; //assign a new card value

        if (userHitTemp > 10) //kings, queens, ans jacks are woth 10
        {
          userHitTemp = 10;
        }

        if (userHitTemp > 1)
        {
         cout << "You decided to hit. Your new card is " << userHitTemp << " points.\n"; //if not an ace, dispaly card value
          tempCardAce = false;
        }
        else
        {
          cout << "You decided to hit. Your new card is an ace.\n"; //if an ace, set bool to true to use later
          tempCardAce = true;
        }

        if (tempCardAce)
        {
          cout << "Would you like your new ace to equal 11? (Otherwise, it will equal a 1)\n"; //ask user if the new ace should be worth 11 or 1 points
          cin >> aceYOrN;
          aceYOrN = correctCharInput(aceYOrN);

          while (aceYOrN != 'n' && aceYOrN != 'N' && aceYOrN != 'y' && aceYOrN != 'Y') //validate user input
          {
            cout << "Invalid input, please enter a new input:\n";
            cin >> aceYOrN;
            aceYOrN = correctCharInput(aceYOrN);
          }

          if (aceYOrN == 'Y' || aceYOrN == 'y') //set ace to 11
          {
            userHitTemp = 11;
          }
          else if (aceYOrN == 'N' || aceYOrN == 'n') //set ace to 1
          {
            userHitTemp = 1;
          }
        }

        userScore += userHitTemp;
        cout << "Your current point total is " << userScore << " points.\n"; //calculate and display new user score

      }
      else
      {
        break; //break if user selects to stay
      }
    }

    if (userScore > 21)
    {
      win = false;
      cout << "You busted!\n"; //if user busts, set win to false
    }
    else
    {
      cout << "The house scored " << compScore << " points.\n"; //display computer score
      if (compScore > 21)
      {
        cout << "The house busted!\n"; //if the house busts, the user wins
        win = true;
      }
      else if (compScore == userScore)
      {
        cout << "You tied with the house.\n"; //if the user and house tie, house wins
        win = false;
      }
      else if (compScore > userScore) //if the house scores more than the player, the house wins
      {
        win = false;
      }
      else
      {
        win = true; //otherwise, the user wins 
      }

    }

    if (win)
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, 2, betAmount, true); //display user won and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, 2, betAmount, false); //display user lost and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n"; //kick out user if bankrupt
      break;
    }

    cout << "Would you like to play again?\n";
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN); //ask user if they wish to play again

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y')
    {
      cout << "Invalid input, please enter a new input:\n"; //validate user input
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}

//###############################################################################################

void highLowGame(int &currentBalance)
{
  int betAmount;
  int baseNum;
  int secondNum; //declare variables for later use
  char hOrL;
  char continueYOrN;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    betAmount = correctIntInput(betAmount);
    betAmount = validBet(currentBalance, betAmount); //display current balance and validate bet
    baseNum = randomWithMax(9) + 1;

    cout << "The first number is " << baseNum << "\nDo you bet (h)igh, or (l)ow?\n"; //display first num and ask user to bet high or low
    cin >> hOrL;
    hOrL = correctCharInput(hOrL);

    while (!(hOrL == 'l' || hOrL == 'L' || hOrL == 'h' || hOrL == 'H')) //validate user input
    {
      cout << "Invalid input, please enter 'H' or 'L'\n";
      cin >> hOrL;
      hOrL = correctCharInput(hOrL);
    }

    secondNum = randomWithMax(9) + 1;
    cout << "The second number is " << secondNum << "\n"; //print second num

    if ((((hOrL == 'l') || (hOrL == 'L')) && (secondNum < baseNum)) || (((hOrL == 'h') || (hOrL == 'H')) && (secondNum > baseNum)))
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, 1, betAmount, true); //if the user bet correctly, print they won and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, 1, betAmount, false); //otherwise, print they lost and update valance
      cout << "Your new balance is " << currentBalance << "\n";
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n"; //kick player out if bankrupt
      break;
    }

    cout << "Would you like to play again?\n";
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN); //ask user if they want to play again

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y')
    {
      cout << "Invalid input, please enter a new input:\n"; //validate user input
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}

//###############################################################################################

void craps(int &currentBalance)
{
  char continueYOrN;
  char passYOrN;
  int betAmount; //define variables for later use
  int diceOne;
  int diceTwo;
  int firstDiceTotal;
  int tempDiceTotal;
  bool win;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    betAmount = correctIntInput(betAmount);
    betAmount = validBet(currentBalance, betAmount); //display current balance and validate user bet
    tempDiceTotal = 0;

    cout << "Would you like to Pass? (Otherwise, No Pass)\n"; //ask user for their bet
    cin >> passYOrN;
    passYOrN = correctCharInput(passYOrN);

    while (passYOrN != 'n' && passYOrN != 'N' && passYOrN != 'y' && passYOrN != 'Y') //validate user input
    {
      cout << "Invalid input, please enter a new input:\n";
      cin >> passYOrN;
      passYOrN = correctCharInput(passYOrN);
    }

    cout << "Roll #1:\n";
    diceOne = randomWithMax(5) + 1;
    diceTwo = randomWithMax(5) + 1;
    firstDiceTotal = diceOne + diceTwo;
    cout << "The first dice rolled a " << diceOne << ", and the second dice rolled a " << diceTwo << ", for a total of " << firstDiceTotal << "\n"; //roll two dice and display their total

    if (firstDiceTotal == 2 || firstDiceTotal == 3 || firstDiceTotal == 12)
    {
      cout << "You rolled craps!\n"; //if user rolls craps

      if (passYOrN == 'y' || passYOrN == 'Y')
      {
        win = false; //pass on craps
      }
      else
      {
        win = true; //no pass on craps
      }

    }
    else if (firstDiceTotal == 7 || firstDiceTotal == 11)
    {
      cout << "You rolled a natural!\n"; //if user rolls natural

      if (passYOrN == 'y' || passYOrN == 'Y')
      {
        win = true; //pass on natural
      }
      else
      {
        win = false; //no pass on natural
      }

    }
    else
    {
      int count = 2;
      while (tempDiceTotal != firstDiceTotal && tempDiceTotal != 7) //otherwise, keep rolling until get same number or seven
      {
        cout << "Press enter to roll again!\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear cin and wait for user input
        cin.get();
        cout << "Roll #" << count << ":\n";
        diceOne = randomWithMax(5) + 1;
        diceTwo = randomWithMax(5) + 1;
        tempDiceTotal = diceOne + diceTwo;
        cout << "The first dice rolled a " << diceOne << ", and the second dice rolled a " << diceTwo << ", for a total of " << tempDiceTotal << "\n"; //roll dice additional times and display their totals
        count += 1;
      }
      if (tempDiceTotal == firstDiceTotal) //if user rolls the same number as their first
      {
        if (passYOrN == 'y' || passYOrN == 'Y')
        {
          win = true; //pass on equal nums
        }
        else
        {
          win = false; //no pass on equal nums
        }
      }
      else if(tempDiceTotal == 7) //if user rolls a seven
      {
        if (passYOrN == 'y' || passYOrN == 'Y')
        {
          win = false; //pass on second 7
        }
        else
        {
          win = true; //no pass on second 7
        }
      }
    }

    if (win)
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, 1, betAmount, true); //display user won and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, 1, betAmount, false);
      cout << "Your new balance is " << currentBalance << "\n"; //display user lost and update balance
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n"; //kick bankrupt player out
      break;
    }

    cout << "Would you like to play again?\n";
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN); //ask user if they want to play again

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y') //validate user input
    {
      cout << "Invalid input, please enter a new input:\n";
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}

//###############################################################################################

void slots(int &currentBalance)
{
  char continueYOrN;
  int betAmount;
  int payout;
  int numOne; //declare variable for later use
  int numTwo;
  int numThree;
  bool win;

  do
  {
    cout << "Your current balance is $" << currentBalance << "\nHow much would you like to bet?\n";
    cin >> betAmount;

    betAmount = correctIntInput(betAmount);
    betAmount = validBet(currentBalance, betAmount); //display current balance and validate bet
    
    cout << "Press enter to play the slots!\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //wait for user input
    cin.get();

    numOne = randomWithMax(9);
    numTwo = randomWithMax(9); //randomize three slot values
    numThree = randomWithMax(9);

    cout << "You spun:   |" << numOne << "| |" << numTwo << "| |" << numThree << "|\n"; //display slot values

    if(numOne == numTwo && numTwo == numThree)
    {
      payout = 99;
      win = true; //if three matching slots, payout 99 times bet
      cout << "Triple digits!\n";
    }
    else if ((numOne == numTwo && numOne != numThree) || (numOne == numThree && numOne != numTwo) || (numTwo == numThree && numTwo != numOne))
    {
      payout = 10;
      win = true;
      cout << "Pair!\n"; //if two match, payout 10 times bet
    }
    else
    {
      payout = 1;
      win = false; //otherwise lose
    }

    if (win)
    {
      cout << "Congratulations, you won your bet!\n";
      updateBalance(currentBalance, payout, betAmount, true); //print user won and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }
    else
    {
      cout << "Looks like you lost your bet!\n";
      updateBalance(currentBalance, payout, betAmount, false); //print user lost and update balance
      cout << "Your new balance is " << currentBalance << "\n";
    }

    if (currentBalance <= 0)
    {
      cout << "Uh oh, you are bankrupt!\n"; //kick out bankrupt player
      break;
    }

    cout << "Would you like to play again?\n";
    cin >> continueYOrN;
    continueYOrN = correctCharInput(continueYOrN); //ask user if they want to continue

    while (continueYOrN != 'n' && continueYOrN != 'N' && continueYOrN != 'y' && continueYOrN != 'Y')
    {
      cout << "Invalid input, please enter a new input:\n"; //validate user input
      cin >> continueYOrN;
      continueYOrN = correctCharInput(continueYOrN);
    }
    cout << "\n\n\n\n";
  }while(!(continueYOrN == 'n' || continueYOrN == 'N'));
}

//###############################################################################################

void testCases()
{
  int sampleBalance = 100;
  int sampleBet = 50;
  int samplePayout = 5;
  int passed = 0; //define values for later use
  int failed = 0;
  bool sampleWin = true;
  char randYOrN;


  cout << "Testing updateBalance() win...\n";
  updateBalance(sampleBalance, samplePayout, sampleBet, sampleWin); //test update balance with a win
  if (sampleBalance == 350)
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }

  sampleWin = false;
  sampleBalance = 100;
  sampleBet = 50;
  cout << "Testing updateBalance() lose...\n";
  updateBalance(sampleBalance, samplePayout, sampleBet, sampleWin); //test update balance with a loss
  if (sampleBalance == 50)
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }

  sampleWin = false;
  sampleBalance = 5;
  sampleBet = 827;
  cout << "Testing updateBalance() negative...\n";
  updateBalance(sampleBalance, samplePayout, sampleBet, sampleWin); //test update balance to get negative value
  if (sampleBalance == 0)
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }
  

  cout << "Testing randomWithMax()...\n";
  for (int i = 0; i < 50; i++)
  {
    cout << randomWithMax(25) << " ";
  }
  cout << "\nLooking at the above 50 numbers, do they represent a random assortment between zero and twenty-five (y or n)?\n";
  cin >> randYOrN; //generate 50 random numbers to test random function, ask user if numbers are random or all same value

  while ((randYOrN != 'n' && randYOrN != 'N' && randYOrN != 'y' && randYOrN != 'Y') || (cin.fail()))
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Invalid input, please enter a new input:\n"; //validate user input
    cin >> randYOrN;
  }
  if (randYOrN == 'y' || randYOrN == 'Y')
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }

  cout << "Testing correctCharInput()...\n";
  char sampleChar = 'c';
  if (correctCharInput(sampleChar) == 'c') //test correct char input
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }

  cout << "Testing correctIntInput()...\n";
  int sampleInt = '4';
  if (correctIntInput(sampleInt) == '4') //test correct int input
  {
    cout << "Pass!\n";
    passed++;
  }
  else
  {
    cout << "Fail!\n";
    failed++;
  }

  sampleBalance = 5;
  sampleBet = 3;
  cout << "Testing validBet()...\n";
   if (validBet(sampleBalance, sampleBet) == sampleBet) //test valid bet
   {
     cout << "Pass!\n";
     passed++;
   }
   else
   {
     cout << "Fail!\n";
     failed++;
   }

  cout << passed << " tests passed.\n"; //display number of tests failed and passed
  cout << failed << " tests failed.\n\n\n\n";


}

//###############################################################################################

void menu(int &curBal)
{
  char choice = 'u';
  cout.setf(ios::fixed);
  do
  {
    cout << "1) Play (H)igh-Low\n2) Play (T)wenty-One\n3) Play (C)raps\n4) Play (S)lots\n5) Play Two (U)p\n6) Run Test Case (D)river\n7) (L)eave Casino\n\nYour current bank balance is $" << setprecision(2) << (double)curBal << "\n";
    cin >> choice;
    choice = correctCharInput(choice); //display menu and get user input, & validate user input

    switch (choice)
    {
      case 'h':
      case 'H':
      highLowGame(curBal);
      break;

      case 't':
      case 'T':
      twentyOne(curBal);
      break;

      case 'c':
      case 'C':
      craps(curBal);
      break;

      case 's':
      case 'S':
      slots(curBal); //different menu options run their respective functions
      break;

      case 'u':
      case 'U':
      twoUp(curBal);
      break;

      case 'd':
      case 'D':
      testCases();
      break;

      case 'l':
      case 'L':
      break;

      default:
      cout << "Invalid menu choice, please input a correct menu option\n\n"; //ask user for correct menu choice
      break;
    }
  }while (!(choice == 'l' || choice == 'L' || curBal <= 0));

  if (curBal <=0)
  {
    cout << "You were thrown out of the casino for betting all of your money away!\n"; //if bankrupt, kick user out of casino
  }
}

//###############################################################################################

int main()
{
  srand((unsigned)time(0)); //seed the rands
  int ogBal;
  int balance = 1; //declare variables for later use

  cout.setf(ios::fixed);
  balance = randomWithMax(100)+100;
  ogBal = balance;
  menu(balance); //set balance and runs menu

  cout << "Your starting balance was $" << setprecision(2) << (double)ogBal << "\n"; //after user leaves, display starting and ending balance values
  cout << "Your final bank balance is $" << setprecision(2) << (double)balance << "\n";

  if (ogBal == balance)
  {
    cout << "Looks like you broke even.\n"; //if user broke even, let them know
  }
  else if (ogBal < balance)
  {
    cout << "You left with a nice, tidy sum of $" << (double)(balance - ogBal) << ". Good job!\n"; //if user made money, let them know
  }
  else if (balance < ogBal)
  {
    cout << "Ouch! Looks like you lost a total of $" << (double)(ogBal - balance) << ". Looks like luck is not on your side.\n"; //if user lost money, let them know
  }

  cout << "Press enter to quit";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //wait for user to quit
  cin.get();
  return 0;

}