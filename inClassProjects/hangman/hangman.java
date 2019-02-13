/*
 * Names: Eli Monnig, Xander Hacking, Jacob Winslow, Lura Rider, Alex Fitzmaurice
 * Date: 01/15/19
 * Description: It's hangman. Come on.
 */

import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class hangman {
    private static final Random randomNumbers = new Random();
    private enum category { ANIMALS, DND, CARS, BOOKS, DESTINY };
    
    private static String[] animalWords = new String[]{"octopus", "dolphin", "elephant",
        "giraffe", "lynx", "hamster", "goldfish", "scorpion", "scarab", "antellope" };
        //all animal words
    private static String[] DNDWords = new String[]{"alchemist", "gold", "dragon",
        "dungeon", "human", "fighter", "warlock", "owlbear", "goblin", "kobold" };
        //all DND words
    private static String[] carWords = new String[]{"chevy", "ford", "porsche",
        "ferrari", "lamborghini", "fiat", "mercedes", "bugatti", "audi", "BMW" };
        //all car words
    private static String[] bookWords = new String[]{"hardback", "paperback", "ink",
        "paper", "frankenstien", "spines", "hobbit", "gatsby", "editor", "hamlet" };
        //all book words
    private static String[] destinyWords = new String[]{"hunter", "titan", "warlock",
        "malfeasance", "bygones", "riskrunner", "izanami", "bergusia", "volundr", "gofannon" };
        //all destiny words
        
        
    static String catName = "";
    public static void main(String[] args) {
        System.out.print('\u000C');
        
        Scanner input = new Scanner(System.in);
        System.out.print("What is your name?");
        String name = input.next();
        int wins = 0;
        int losses = 0;
        while (true) {
            category cat = category.DESTINY;   //catagory that player chooses, initilized to something for the sake of intializing.
            
            System.out.print('\u000C');
            
            System.out.print(name + ", please select a category from the following: ");
            System.out.println();
            System.out.println("1. Animals");
            System.out.println("2. DND");
            System.out.println("3. Cars");
            System.out.println("4. Books");
            System.out.println("5. Destiny");
            System.out.println("6. Random");
            System.out.println("0. Exit");
            
            String secretWord = "";
            int choice = input.nextInt();   //reads next integer and stores in choice
            switch(choice)
            {
                case 1:  
                {
                    cat = category.ANIMALS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Animals";
                    break;
                } //end case 1
                case 2:
                {
                    cat = category.DND;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Dungeons and Dragons";
                    break;
                } //end case 2
                case 3:
                {
                    cat = category.CARS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Cars";
                    break;
                } //end case 3
                case 4:
                {
                    cat = category.BOOKS;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Books";
                    break;
                } //end case 4
                case 5:
                {
                    cat = category.DESTINY;
                    secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                    catName = "Destiny";
                    break;
                } //end case 5
                case 6: 
                {
                    switch(randomNumbers.nextInt(4) + 1) //switch that picks a random case
                    {
                        case 1:  
                        {
                            cat = category.ANIMALS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Animals";
                            break;
                        } //end case 1
                        case 2:
                        {
                            cat = category.DND;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Dungeons and Dragons";
                            break;
                        } //end case 2
                        case 3:
                        {
                            cat = category.CARS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Cars";
                            break;
                        } //end case 3
                        case 4:
                        {
                            cat = category.BOOKS;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Books";
                            break;
                        } //end case 4
                        case 5:
                        {
                            cat = category.DESTINY;
                            secretWord = getWord(cat);  //sets secret word to a random word in the catagory
                            catName = "Destiny";
                            break;
                        } //end case 5
                    }//end random switch
                    break;
                }//end case 6
                default:
                {
                    cat = category.ANIMALS;
                    System.exit(0);
                } //end default case
            }
            
            int incorrects = 0; //number of incorrect guesses
            ArrayList<String> wrongGuesses = new ArrayList<String>();   //exact character that is incorrect
            char[] wordCharArray = secretWord.toCharArray();    //secret word as a char array, to be disregarded
            String[] wordArray = new String[secretWord.length()];   //String array, to hold wordCharArray, but in Strings
            for (int i = 0; i < wordArray.length; i++) {
                wordArray[i] = String.valueOf(wordCharArray[i]);    //converts wordCharArray into Strings
            }//end for i loop
            boolean[] isGuessed = new boolean[secretWord.length()]; //array for if the letter that is a part of the word has been guessed
            boolean complete = false;   //if the game is complete either won or lost
            boolean fail = false;   //if the game was lost
            for(boolean b: isGuessed) {//for each in isGuessed
                b = false;  //each part of isGuessed is false
            }//end for each loop
                while (!complete) {
                complete = true;    //sets complete to true each time the while loops, to be changed later in the loop
                makeGallows(incorrects);    //makes the gallows based on how many incorrect guesses
                System.out.println("Wrong guesses");
                for (int i = 0; i < incorrects; i++) {
                    System.out.print(wrongGuesses.get(i) + " ");    //prints all wrong guesses
                }//end for i loop
                System.out.println();
                
                for (int i = 0; i < secretWord.length(); i++) {
                    //prints word, filling in all characters that are correct
                    if (isGuessed[i]) {//if has been guess
                        System.out.print(wordArray[i] + " ");   //prints lettter and a space
                    }   //end if
                    else {
                        System.out.print("_ "); //prints dash and a space
                    }//end if
                }//end for i loop
                System.out.println();
                
                String guess = "  ";    //Takes in the next word
                while (guess.length() > 1) {//makes sure that guess is a Char
                    System.out.println(name + ", please enter a single-character guess.");
                    guess = input.next();    //Takes in the next word
                    guess = guess.toLowerCase();    //makes guess lowercase 
                }//end while loop
                boolean correct = false;
                for(int i = 0; i < wordArray.length; i++) {
                    if(guess.equals(wordArray[i])) {//if guess is the same as any letter
                        isGuessed[i] = true;
                        correct = true;
                    }//end if
                }//end for i loop
                if (!correct) {   //if guess was none of the letters
                    if(!wrongGuesses.contains(guess)) {//if guess isn't already in wrongGuesses
                        wrongGuesses.add(guess);
                        incorrects++;
                    }//end if
                }//end if
                //checks if the player has won
                for(boolean t: isGuessed) { //for each value of isGuessed
                    if (!t) {//if the value is false
                        complete = false;   //used for the game to end
                    }// end if
                }//end for each llop
                if (incorrects >= 6) {
                    complete = true;    //used for the game to end
                    fail = true;//used for the player to lose
                }//end if
            }//end while loop
            //one last time
            makeGallows(incorrects);
            System.out.println("Wrong guesses");
            for (int i = 0; i < incorrects; i++) {
                System.out.print(wrongGuesses.get(i) + " ");
            }//end for i loop
            System.out.println();
            
            for (int i = 0; i < secretWord.length(); i++) {
                if (isGuessed[i]) {
                    System.out.print(wordArray[i] + " ");
                }//end if
                else {
                    System.out.print("_ ");
                }//end if
            }//end for i loop
            System.out.println();
            if (fail) { //if the player lost
                System.out.println(name + ",you lose. The word was " + secretWord + ".");
                losses++;
            }//end if
            else {
                System.out.println(name + ", you win!");
                wins++;
            }//end if
            System.out.print("You have won " + wins + " time(s) and loss " + losses + " time(s).");
            System.out.println();
            System.out.println("Would you like to play again? (Yes or No)");
            String answer = input.next();   //stores next word
            answer = answer.toLowerCase();  //set to lower case
            if(answer.equals("no")) {   //if player does not want to play again
                System.exit(0); //DOESN'T CLOSE THE PROGRAM, FOR SOME REASON.
            }//end if
        }//end while loop
    }//end main()
    
    public static String getWord(category cat) {
        if(cat == category.ANIMALS) {
            return animalWords[randomNumbers.nextInt(9)];   //chooses a random word from the animal category
        }//end if
        else if(cat == category.DND) {
            return DNDWords[randomNumbers.nextInt(9)];   //chooses a random word from the DND category
        }//end if
        else if(cat == category.CARS) {
            return carWords[randomNumbers.nextInt(9)];   //chooses a random word from the car category
        }//end if
        else if(cat == category.BOOKS) {
            return bookWords[randomNumbers.nextInt(9)];   //chooses a random word from the book category
        }//end if
        else if(cat == category.DESTINY) {
            return destinyWords[randomNumbers.nextInt(9)];   //chooses a random word from the destiny category
        }//end if
        System.exit(1);
        return "1";//returning for the sake of returning
    }//end getWord();
    
    //makes the hangman picture based on incorrect answers. You know what I'm talkin about.
    public static void makeGallows(int incorrects) {
        System.out.print('\u000C'); //clears the screen
        System.out.println("Category: " + catName);
        System.out.println("_______");
        System.out.println("|     |");
        if (incorrects >= 1) {
            System.out.println("|     0");
            if (incorrects == 2) {
                System.out.println("|     | ");
                System.out.println("|      ");
            }//end if
            else if(incorrects == 3) {
                System.out.println("|     |\\");
                System.out.println("|      ");
            }//end else if
            else if(incorrects >= 4) {
                System.out.println("|    /|\\");
                if (incorrects == 5) {
                    System.out.println("|      \\");
                }//end if
                else if (incorrects == 6) {
                    System.out.println("|    / \\");
                }//end else if
                else {
                    System.out.println("|      ");
                }//end else
            }//end else if
            else {
            System.out.println("|      ");
            System.out.println("|      ");
            }//end else
        }//end if
        else {
            System.out.println("|      ");
            System.out.println("|      ");
            System.out.println("|      ");
        }//end else
        System.out.println("|      ");
        System.out.println("|      ");
        System.out.println();
    }//end makeGallows()
}
//end class