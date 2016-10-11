// Scrabble.cpp

using namespace System;
using namespace System::Collections::Generic;

enum class Characters { NEWLINE = 13 };

// Letter represents the different tile letters and the blank, represented
// by _
enum class Letter { _ = 0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S,
T, U, V, W, X, Y, Z };

// PlayType represents the direction of play: across, down, or pass
enum class PlayType { Across, Down, Pass };

// The types of spaces on the board.
// DLS == Double Letter Score
// DWS == Double Word Score
// TLS == Triple Letter Score
// TWS == Triple Word Score
enum class SpaceType { Normal = 0, DLS = 1, DWS = 2, TLS = 3, TWS = 4, Center = 5 };

// A Scrabble Tile contains a letter and a fixed point value
// that depends on the letter. We also include a property for the
// letter that a blank tile represents once it is played.
// Tiles are not the same as board spaces: tiles are placed into
// board spaces as play goes on.
ref struct Tile
{
   property Letter LetterValue;
   property int PointValue;
   property Char BlankValue;

   // This array contains the static point values of each tile
   // in alphabetical order, starting with the blank
   static array<int>^ point_values =
   {0, 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 2, 1, 1, 3, 10, 1, 1, 1, 1,
   4, 3, 8, 4, 10};

   // The Tile constructor initializes the tile from its letter
   // and the point value
   Tile(Letter letter)
   {
      LetterValue = letter;
      PointValue = point_values[ safe_cast<int>( letter )];
   }

   // Used when displaying the tile on the gameboard
   virtual String^ ToString() override
   {
      // Format(LetterValue) won't work because the compiler
      // won't be able to identify the right overload when the
      // type is an enum class
      return String::Format("{0}", LetterValue);
   }
};

ref struct Player
{
   int number; // number specifying which player this is.

   List<Tile^>^ tiles; // the player's rack of tiles

   // the number of tiles in the player's rack
   // normally 7, but may be less at the end of the game
   property int TileCount
   {
      int get() { return tiles->Count; }
   }

   property String^ Name; // the name of the player

   property int Score; // the player's cumulative point total

   // The constructor
   Player(String^ s, int n) : number(n)
   {
      Name = s;
      Score = 0;
      Console::WriteLine("Player {0} is {1}.", n, Name);
   }

   // Displays the player's rack of tiles
   void PrintPlayerTiles()
   {
      Console::WriteLine("Tiles in hand: ");
      for (int j = 0; j < TileCount; j++)
      {
         Console::Write("{0} ", tiles[j]->ToString());
      }
      Console::WriteLine();
   }
};

// This class is the main class including all the functionality
// and data for a Scrabble game.
ref class ScrabbleGame
{
   // literals are constants that can be initialized in the class body
   literal int TILE_COUNT = 100;  // the number of tiles altogether
   literal int MAX_TILES_IN_HAND = 7;  // the maximum number of tiles in each hand

   // the array of players
   array<Player^>^ players;

   // spaces is the array of board spaces.
   static array<int, 2>^ spaces = gcnew array<int, 2>
   { { 4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4 },
   {   0, 2, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0 },
   {   0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0 },
   {   1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 1 },
   {   0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
   {   0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0 },
   {   0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 },
   {   4, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 1, 0, 0, 4 },
   {   0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 },
   {   0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0 },
   {   0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
   {   1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 1 },
   {   0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0 },
   {   0, 2, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0 },
   {   4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4 }};

   // spaceTypeColors tell us how to draw the tiles when displaying the
   // board at the console
   static initonly array<ConsoleColor>^ spaceTypeColors = { ConsoleColor::Gray,
      ConsoleColor::Cyan, ConsoleColor::Red, ConsoleColor::Blue,
      ConsoleColor::DarkRed, ConsoleColor::Red };

   // the gameboard representing all played tiles
   array<Tile^, 2>^ gameBoard;

   // the bag, containing the tiles that have not yet been drawn
   List<Tile^>^ bag;

   // an array of the amount of each tile
   static initonly array<int>^ tilePopulation = gcnew array<int>
   { 2, 9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2,
     1  };

   int nPlayer; // the number of players in this game
   int playerNum; // the current player
   int moveNum;  // count of the number of moves
   Random^ random; // a random number generator
   bool gameOver;  // set to true when a condition results in the end of the game
   bool endBonus; // true at the end of the game when a player uses up all of
   // his or her tiles

   // pass_count counts the number of consecutive passes
   // (when players do not make a play)
   // This is used to find out if everyone passes one after the other,
   // in which case the game is over.
   int pass_count;

   // There are 15 spaces in the board. These constants are used in the static
   // constructor to create the board using symmetry
   literal int BOARD_SIZE = 15;
   literal int BOARD_SIZEM1 = BOARD_SIZE - 1;
   literal int BOARD_MID = 7;
   literal int TILE_TYPES = 27;

public:
   // The instance constructor creates the array of players
   // and the tile bag, which would have to be re-created for
   // each game.
   ScrabbleGame(unsigned int numPlayers) : nPlayer(numPlayers)
   {
      moveNum = 0;
      random = gcnew Random();
      // Create the players
      players = gcnew array<Player^>(numPlayers);
      for (unsigned int i = 0; i < numPlayers; i++)
      {
         Console::Write("Player {0} enter name: ", i);
         String^ s  = Console::ReadLine();
         players[i] = gcnew Player(s, i);
      }
      // Initialize the bag tiles
      bag = gcnew List<Tile^>(TILE_COUNT);
      for (int i = 0; i < TILE_TYPES; i++)
      {
         for (int j = 0; j < tilePopulation[i]; j++)
         {
            Letter letter = safe_cast<Letter>(i);
            bag->Add(gcnew Tile(letter));
         }
      }
      // The gameboard consists of an array of null pointers initially.
      gameBoard = gcnew array<Tile^, 2>(BOARD_SIZE, BOARD_SIZE);
   }


   // Display the current scores and tiles in the bag or
   // in each player's rack
   void PrintScores()
   {
      Console::Write("Current stats: ");
      if (bag->Count != 0)
      {
         Console::WriteLine("{0} tiles remaining in tile bag.", bag->Count);
      }
      else
      {
         Console::WriteLine("No tiles remaining in tile bag.");
      }

      for (int i = 0; i < nPlayer; i++)
      {
         Console::WriteLine("{0,-10} -- Score: {1,3} Number of tiles: {2} -- ",
            players[i]->Name, players[i]->Score, players[i]->TileCount);
      }
   }

   // Display the permanent gameboard (overload)
   void PrintBoard()
   {
      PrintBoard(gameBoard);
   }

   // Display the gameboard. This overload takes a board
   // as an argument, so it is possible to display the proposed
   // play before committing it to the permanent gameboard.
   void PrintBoard(array<Tile^, 2>^ board)
   {
      Console::WriteLine();
      Console::Write("   ");
      for (int i = 0; i < BOARD_SIZE; i++)
         Console::Write(" {0:X1} ", i);
      Console::WriteLine();
      for (int i = 0; i < BOARD_SIZE; i++)
      {
         Console::Write(" {0:X1} ", i);
         for (int j = 0; j < BOARD_SIZE; j++)
         {
            if (board[i, j] == nullptr)
            {
               Console::BackgroundColor = spaceTypeColors[spaces[i, j]];
               Console::Write("   ");
               // The foreground and background colors are restored to
               // the colors that existed when the current process began.
               Console::ResetColor();
            }
            else
            {
               Console::BackgroundColor = ConsoleColor::Black;
               Console::ForegroundColor = ConsoleColor::White;
               Letter letter = board[i, j]->LetterValue;
               if (letter == Letter::_)
               {
                  Console::Write(" {0:1} ", board[i,j]->BlankValue);
               }
               else
               {
                  Console::Write(" {0:1} ", board[i, j]);
               }
               Console::ResetColor();
            }
         }
         Console::WriteLine();
      }
      Console::WriteLine();
   }

   // Draw a tile from the bag and return it.
   // Returns null if the bag is empty.
   // The parameter keep is true if the tile is drawn during the game,
   // false if the tile is drawn at the beginning of the game
   // to see who goes first.
   Tile^ DrawTile(bool keep)
   {
      if (bag->Count == 0) // return nullptr if there are no tiles left
      {
         return nullptr;
      }
      int random_index = safe_cast<int>((random->NextDouble() * bag->Count) );
      Tile^ tile = bag[random_index];
      if (keep)
         bag->RemoveAt(random_index);
      return tile;
   }

   // Determine who goes first and draw tiles. Each player draws
   // a tile and whoever has the letter closest to the beginning of
   // the alphabet goes first. Return the player number of the first
   // player.
   int PreGame()
   {
      Console::WriteLine("Each player draws a tile to see who goes first.\n"
         "The player closest to the beginning of the alphabet goes first.");
      // Each player draws one tile to see who goes first. If both players
      // draw the same tile, everyone redraws.
      array<Tile^>^ drawTiles = gcnew array<Tile^>(nPlayer);
      bool firstPlayerFound = false;
      int firstPlayerIndex = 0;
      do
      {

         for (int i = 0; i < nPlayer; i++)
         {
            drawTiles[i] = DrawTile(false);
            Console::WriteLine("{0} draws {1}.", players[i]->Name,
               drawTiles[i]->LetterValue);
            if (i > 0 && drawTiles[i]->LetterValue <
               drawTiles[firstPlayerIndex]->LetterValue)
            {
               firstPlayerIndex = i;
            }
         }
         firstPlayerFound = true;

         // if someone else has the same tile, throw back and redraw
         for (int i = 0; i < nPlayer; i++)
         {
            if (i == firstPlayerIndex)
               continue;
            if (drawTiles[i]->LetterValue ==
               drawTiles[firstPlayerIndex]->LetterValue)
            {
               Console::WriteLine("Duplicate tile {0}. Redraw.",
                  drawTiles[i]->LetterValue);
               firstPlayerFound = false;
            }
         }
      } while (! firstPlayerFound );
      Console::WriteLine("{0} goes first.", players[firstPlayerIndex]->Name );

      // Everyone draws their tiles
      for (int i = 0; i < nPlayer; i++)
      {
         players[i]->tiles = gcnew List<Tile^>(MAX_TILES_IN_HAND);
         for (int j = 0; j < MAX_TILES_IN_HAND; j++)
         {
            players[i]->tiles->Add( DrawTile(true));
         }
         Console::Write("{0} draws tiles: ", players[i]->Name, i);
         for (int j = 0; j < MAX_TILES_IN_HAND; j++)
         {
            Console::Write("{0} ", players[i]->tiles[j]->ToString());
         }
         Console::WriteLine();
      }
      return firstPlayerIndex;
   }

   // Play plays the game from start to finish
   // return the winning player
   Player^ Play(int firstPlayer)
   {
      playerNum = firstPlayer;
      gameOver = false;
      do
      {
         gameOver = PlayerMove();
         playerNum = ( playerNum + 1 ) % nPlayer;
         PrintScores();
         Console::WriteLine("Press ENTER to continue...");
         Console::ReadLine();
         Console::Clear();
         moveNum++;
      } while (! gameOver);

      // The game is over.
      AdjustPointTotals();
      Console::WriteLine("Final scores: ");
      PrintScores();
      int winningPlayer = FindWinner();
      if (winningPlayer != -1)
      {
         return players[winningPlayer];
      }
      else return nullptr;
   }

   // At the end of the game, point totals are adjusted according to
   // the following scheme: all players lose the point total of any
   // unplayed tiles; if a player plays all her tiles, she
   // receives the point totals of all unplayed tiles
   void AdjustPointTotals()
   {
      int total_point_bonus = 0;
      for (int i=0; i < nPlayer; i++)
      {
         if (players[i]->TileCount > 0)
         {
            Console::WriteLine("{0} remaining tiles and score adjustments: ",
               players[i]->Name);
            int point_deduction = 0;
            for each (Tile^ t in players[i]->tiles)
            {
               Console::Write(" {0} -{1}  ", t->LetterValue, t->PointValue);
               point_deduction += t->PointValue;
            }
            Console::WriteLine();
            players[i]->Score -= point_deduction;
            total_point_bonus += point_deduction;
         }
      }
      if (endBonus)
      {
         Console::WriteLine("{0}'s bonus for using the last tile is {1}.",
            players[playerNum]->Name, total_point_bonus);
         players[playerNum]->Score += total_point_bonus;
      }
   }

    // Find out which player won
   int FindWinner()
   {
      if (! gameOver)
      {
         return -1;
      }
      int leadingPlayer = 0;
      for (int i = 1; i < nPlayer; i++)
      {
         if (players[i]->Score > players[leadingPlayer]->Score)
         {
            leadingPlayer = i;
         }
      }
      for (int i = 0; i < nPlayer; i++)
      {
         // check for a tie
         if (i != leadingPlayer && players[i]->Score ==
                players[leadingPlayer]->Score)
         {
            return -1;
         }
      }
      return leadingPlayer;
   }

   // Implement a pass move in which a player throws back a certain
   // number of her tiles and draws new ones
   // return true if successful
   bool Pass(List<Tile^>^ workingTiles)
   {
      if (bag->Count != 0)
      {
         int code;
         // Get the desired tiles to replace to
         // the bag from the user
         Console::WriteLine("Enter tiles to throw back: ");
         do
         {
            code = Console::Read();
            wchar_t character = safe_cast<wchar_t>(code);
            Letter letter = Letter::_;
            if (character == safe_cast<wchar_t>(Characters::NEWLINE))
            {
               Console::ReadLine();
               break;
            }
            if (character == '_')
            {
               letter = Letter::_;
            }
            else if (Char::IsLetter(character))
            {
               if (Char::IsUpper(character))
               {
                  letter = safe_cast<Letter>(character - 'A' + 1);
               }
               else // character is a lowercase letter
               {
                  letter = safe_cast<Letter>(character - 'a' + 1);
               }
            }

            // See if the letter is in the player's hand
            Tile^ tile = gcnew Tile(letter);
            Tile^ tileToRemove = nullptr;
            bool tileFound = false;
            for each (Tile^ t in workingTiles)
            {
               if (t->LetterValue == tile->LetterValue)
               {
                  tileToRemove = t;
                  tileFound = true;
                  break;
               }
            }
            if ( tileFound == true)
            {
               workingTiles->Remove( tileToRemove );
               bag->Add(tile);
            }
            else // The letter was not found.
            {
               Console::WriteLine("You do not have enough {0}s to pass back.",
                  letter);
               Console::WriteLine("Press any key to continue...");
               Console::ReadLine();
               return false;
            }
         } while (code != safe_cast<int>('\n'));
      }  // if bag->Count == 0

      Console::Write("Are you sure you want to pass (Y/N)?");
      String^ response = Console::ReadLine();
      if (response->StartsWith( "Y") || response->StartsWith("y"))
      {
         if (bag->Count > 0)
         {
            Console::Write("{0} draws tiles: ", players[playerNum]->Name);
            // Copy the working tiles to the player tiles
            players[playerNum]->tiles = workingTiles;
            while ( players[playerNum]->tiles->Count < MAX_TILES_IN_HAND)
            {
               Tile^ tile = DrawTile(true);
               if (tile != nullptr)
               {
                  players[playerNum]->tiles->Add(tile);
                  Console::Write(" {0} ", tile->ToString());
               }
               else // the bag is empty
               {
                  Console::WriteLine("\nThe tile bag is empty.");
                  break;
               }
            }
            Console::WriteLine();
         }
      }
      else
      {
         // a false return will indicate that the user has
         // changed his/her mind and may not want to pass
         return false;
      }
      return true;
   }

private:
   PlayType GetPlayType()
   {
      // Input the direction to play
      Console::WriteLine(
      "Enter Direction to Play (A = across, D = down) or P to pass:");
      String^ playTypeString = Console::ReadLine();

      if (playTypeString == "P")
      {
         return PlayType::Pass;
      }
      if (playTypeString == "A")
      {
         return PlayType::Across;
      }
      else if (playTypeString == "D")
      {
         return PlayType::Down;
      }
      else
      {
         Console::WriteLine("Sorry, I didn't understand that input.");
         throw gcnew Exception();
      }
   }

   // Get the position of the start of the play on the board
   bool GetPlayStartPosition(int% row, int% col)
   {
      // Input the row and column of the first letter
      Console::Write(
      "Enter Location to Play as [row][col]: 00 (top left) to EE (bottom right): ");
      String^ locString = Console::ReadLine();

      // parse as a hex number
      int x = Int32::Parse(locString,
         System::Globalization::NumberStyles::HexNumber);
      row = x / 16;
      col = x % 16;
      if (row > 14 || col > 14 || row < 0 || col < 0)
      {
         Console::WriteLine("I did not understand that input.");
         Console::WriteLine("The first digit is the row (0 to E);"
            " the second is the column (0 to E).");
         throw gcnew Exception();
      }

      // check to see that this is an unoccupied space
      if (gameBoard[row, col] != nullptr)
      {
         Console::WriteLine("Sorry, that space is occupied by the tile: {0}",
            gameBoard[row, col]);
         return false;
      }
      return true;
   }

   // return true if the play is successful
   // return false if the play is invalid and needs to be restarted
   bool GetTilesForPlay(int row, int col, PlayType playType,
                        List<Tile^>^ workingTiles, array<Tile^, 2>^ workingBoard )
   {
      // Get the desired tiles to play from the user
      Console::WriteLine(
         "Enter letters to play (_<letter> to play a blank as <letter>): ");
      int code;

      do
      {
         code = Console::Read();
         wchar_t character = safe_cast<wchar_t>(code);
         Letter letter = Letter::_;
         if (character == safe_cast<wchar_t>(Characters::NEWLINE))
         {
            Console::ReadLine();
            break;
         }
         if (character == '_')
         {
            letter = Letter::_;
            // If a blank is entered, read the next character
            code = Console::Read();
            character = safe_cast<wchar_t>(code);
         }
         else if (Char::IsLetter(character))
         {
            if (Char::IsUpper(character))
            {
               letter = safe_cast<Letter>(character - 'A' + 1);
            }
            else // character is a lowercase letter
            {
               letter = safe_cast<Letter>(character - 'a' + 1);
            }
         }

         // See if the letter is in the player's hand
         Tile^ tile = gcnew Tile(letter);
         if (letter == Letter::_)
         {
            tile->BlankValue = character;
         }
         Tile^ tileToRemove = nullptr;
         bool tileFound = false;
         for each (Tile^ t in workingTiles)
         {
            if (t->LetterValue == tile->LetterValue)
            {
               tileToRemove = t;
               tileFound = true;
            }
         }
         if ( tileFound )
         {
            workingTiles->Remove( tileToRemove );
            workingBoard[row, col] = tile;
            if (playType == PlayType::Across)
            {
               while (col < BOARD_SIZE && workingBoard[row, col] != nullptr)
               {
                  col++;
               }
               // we've reached the end of the board, so the play is complete.
               if (col == BOARD_SIZE)
               {
                  // consume any additional input
                  Console::ReadLine();
                  return true;
               }
            }
            else
            {
               while (row < BOARD_SIZE && workingBoard[row, col] != nullptr)
               {
                  row++;
               }
               if (row == BOARD_SIZE)
               {
                  // consume any additional input
                  Console::ReadLine();
                  return true;
               }
            }
         }
         else // The letter was not found.
         {
            Console::WriteLine("You do not have enough {0}s to play.", letter);
            // consume any additional character input
            Console::ReadLine();
            return false;
         }

      } while (code != safe_cast<int>('\n'));

      return true;
   }

   // returns true if the player accepts the play
   bool ConfirmPlay(int score)
   {
      Console::WriteLine("This play is worth {0} points.", score);
      Console::Write("Is this your final play (Y/N)?");
      String^ response = Console::ReadLine();
      if (response->StartsWith( "Y") || response->StartsWith("y"))
      {
         // reset the pass count
         pass_count = 0;
         return true;
      }
      return false;
   }

   // returns the number of tiles drawn
   int ReplacePlayedTiles()
   {
      int count = 0;
      Console::Write("{0} draws tiles: ", players[playerNum]->Name);

      while ( players[playerNum]->tiles->Count < MAX_TILES_IN_HAND)
      {
         Tile^ tile = DrawTile(true);
         if (tile != nullptr)
         {
            count++;
            players[playerNum]->tiles->Add(tile);
            Console::Write(" {0} ", tile->ToString());
         }
         else // the bag is empty
         {
            Console::WriteLine("\nThe tile bag is empty.");
            return count;
         }
      }
      Console::WriteLine();
      return count;
   }
   // commit the confirmed play to the permanent gameboard
   void RecordPlay(List<Tile^>^ workingTiles, array<Tile^, 2>^ workingBoard)
   {
      // Copy the working tiles to the player tiles
      players[playerNum]->tiles = workingTiles;

      // Copy the working board to the board.
      for (int i = 0; i <BOARD_SIZE; i++)
      {
         for (int j = 0; j <BOARD_SIZE; j++)
         {
            gameBoard[i, j] = workingBoard[i, j];
         }
      }
   }

   // update a player's score
   // return the new point total
   int UpdateScore(int playerNum, int scoreForPlay)
   {
      // Increment the player's score
      players[playerNum]->Score += scoreForPlay;
      return players[playerNum]->Score;
   }

   array<Tile^, 2>^ GetWorkingBoard()
   {
      array<Tile^, 2>^ workingBoard = gcnew array<Tile^, 2>(BOARD_SIZE, BOARD_SIZE);
      // Copy the board into a working board
      for (int i = 0; i < BOARD_SIZE; i++)
      {
         for (int j = 0; j < BOARD_SIZE; j++)
         {
            workingBoard[i, j] = gameBoard[i, j];
         }
      }
      return workingBoard;
   }

   List<Tile^>^ GetWorkingTiles()
   {
      List<Tile^>^ workingTiles = gcnew List<Tile^>(MAX_TILES_IN_HAND);
      // Copy each tile into a working hand
      for each(Tile^ t in players[playerNum]->tiles)
      {
         workingTiles->Add(t);
      }
      return workingTiles;
   }

public:

   // PlayerMove implements a player making a play.
   // Returns true if the game is over.
   bool PlayerMove()
   {
      bool gameOver = false;
      bool moveComplete = false;

      while (! moveComplete)
      {
         try
         {
            List<Tile^>^ workingTiles = GetWorkingTiles();
            array<Tile^, 2>^ workingBoard = GetWorkingBoard();
            PrintBoard();
            Console::WriteLine("{0}'s turn.", players[playerNum]->Name);
            players[playerNum]->PrintPlayerTiles();

            PlayType playType = GetPlayType();

            if ( playType == PlayType::Pass)
            {
               moveComplete = Pass(workingTiles);
               if (moveComplete)
               {
                  // the pass was completed
                  pass_count++;
                  // if everyone passes and the bag is empty, the game ends
                  if (pass_count == nPlayer && bag->Count == 0)
                  {
                     gameOver = true;
                  }
                  return gameOver;
               }
               else
               {
                  // the pass was cancelled, restart play
                  continue;
               }
            }
            int row, col;
            if (! GetPlayStartPosition(row, col))
               continue;
            if (! GetTilesForPlay(row, col, playType, workingTiles, workingBoard))
               continue;

            // Calculate the score
            int scoreForPlay = CalculateScore(row, col, playType, workingBoard);
            PrintBoard(workingBoard);
            if (scoreForPlay == -1)
            {
               Console::WriteLine("The move is not a legal move.");
               if (moveNum == 0)
               {
                  Console::WriteLine("The first play must use the center square.");
               }
               else
               {
                  Console::WriteLine(
                  "You must use at least one existing tile on the board.");
               }
               Console::WriteLine();
               continue;
            }

            if (!ConfirmPlay(scoreForPlay))
               continue;

            RecordPlay(workingTiles, workingBoard);

            // if more tiles are in the bag, draw tiles to replace those played
            if (bag->Count > 0)
            {
               ReplacePlayedTiles();
            }

            // the game ends when a player "goes out" -- she uses up all
            // the tiles in her hand and there are none in the bag.
            // The player is eligible for the end game bonus.
            if (bag->Count == 0 && players[playerNum]->tiles->Count == 0)
            {
               endBonus = true;
               gameOver = true;
            }
            UpdateScore(playerNum, scoreForPlay);
            moveComplete = true;
         }
         catch(Exception^)
         {
            moveComplete = false;
         }
      }
      return gameOver;
   }

   // This function calculates the score for a move, if the move is a legal play.
   // If the move is not legal, returns -1.
   int CalculateScore(int row, int col, PlayType direction,
                      array<Tile^, 2>^ newBoard)
   {
      int cumScore = 0;
      PlayType crossDirection;

      int wordScore = 0;
      bool letterBonus = false;
      bool wordBonus = false;
      int letterMultiplier = 1;
      int wordMultiplier = 1;
      bool isLegalMove = false;
      int tilesPlayed = 0;

      if (direction == PlayType::Down)
      {
         crossDirection = PlayType::Across;
         // Find the start of the word being made in the main direction
         while (row >= 0 && newBoard[row, col] != nullptr)
         {
            row--;
         }
         // we overshoot, so now back off by one
         row++;
      }
      else // PlayType::Across
      {
         crossDirection = PlayType::Down;
         while (col >= 0 && newBoard[row, col] != nullptr)
         {
            col--;
         }
         // we overshoot, so back off by one
         col++;
      }

      while ( row < BOARD_SIZE && col < BOARD_SIZE && newBoard[row, col] != nullptr)
      {
         if (moveNum == 0 && row == 7 && col == 7)
         {
            isLegalMove = true;
         }
         letterMultiplier = 1;
         // if the old gameboard space here was empty,
         // look at the space below the tile
         if (gameBoard[row, col] == nullptr)
         {
            tilesPlayed++;
            switch (spaces[row, col])
            {
            case SpaceType::DLS:
               letterBonus = true;
               letterMultiplier = 2;
               break;
            case SpaceType::Center:
            case SpaceType::DWS:
               wordBonus = true;
               wordMultiplier = 2;
               break;
            case SpaceType::TLS:
               letterBonus = true;
               letterMultiplier = 3;
               break;
            case SpaceType::TWS:
               wordBonus = true;
               wordMultiplier = 3;
               break;
            default:
               break;
            }
            // identify any cross-words by moving backward to the
            // first nonempty space
            int rowCrossBegin = row;
            int colCrossBegin = col;
            int rowCross = row;
            int colCross = col;
            int crossScore = 0;
            if (crossDirection == PlayType::Down)
            {
               while ( rowCrossBegin >= 0 &&
                  newBoard[rowCrossBegin, colCrossBegin] != nullptr)
               {
                  rowCrossBegin--;
               }
               rowCrossBegin++; // increment to beginning of word
            }
            else // cross-direction is across
            {
               while ( colCrossBegin >= 0 &&
                  newBoard[rowCrossBegin, colCrossBegin] != nullptr)
               {
                  colCrossBegin--;
               }
               colCrossBegin++; // increment to the beginning of word
            }

            // Now scan forward for crosswords
            int rowCrossEnd = row;
            int colCrossEnd = col;
            if (crossDirection == PlayType::Down)
            {
               while ( rowCrossEnd < BOARD_SIZE &&
                  newBoard[rowCrossEnd, colCrossEnd] != nullptr)
               {
                  rowCrossEnd++;
               }
               rowCrossEnd--; // decrement to beginning of word
            }
            else // cross-direction is across
            {
               while ( colCrossEnd < BOARD_SIZE &&
                  newBoard[rowCrossEnd, colCrossEnd] != nullptr)
               {
                  colCrossEnd++;
               }
               colCrossEnd--; // decrement to the beginning of word
            }
            if (rowCrossBegin != rowCrossEnd ||
                colCrossBegin != colCrossEnd)
            {
               // a crossword was found
               // this counts as using existing tiles,
               // so this is definitely a legal move
               isLegalMove = true;
               if (crossDirection == PlayType::Down)
               {
                  for (rowCross = rowCrossBegin; rowCross <= rowCrossEnd;
                     rowCross++)
                  {
                     // You only account for special bonuses if the tile on that
                     // bonus square is one you played.
                     if (rowCross == row && colCross == col)
                     {
                        crossScore += newBoard[rowCross, colCross]->PointValue
                           * letterMultiplier;
                     }
                     else
                        crossScore += newBoard[rowCross, colCross]->PointValue;
                  }
               }
               else
               {
                  for (colCross = colCrossBegin; colCross <= colCrossEnd;
                     colCross++)
                  {
                     if (rowCross == row && colCross == col)
                     {
                        crossScore += newBoard[rowCross, colCross]->PointValue
                           * letterMultiplier;
                     }
                     else
                        crossScore += newBoard[rowCross, colCross]->PointValue;
                  }
               }
               crossScore *= wordMultiplier;
               cumScore += crossScore;
            } // end of block for if there is a cross-word

         } // end of block for if the space has a new tile on it
         else
         {
            // The space is occupied by a letter that was already there.
            // All plays other than the first must contain a letter that
            // is already present, so if this is the case, then the play is
            // a legal play.
            isLegalMove = true;
         }

         wordScore += letterMultiplier * newBoard[row, col]->PointValue;

         if (direction == PlayType::Down)
            row++;
         else
            col++;
      }
      wordScore *= wordMultiplier;
      cumScore += wordScore;
      // Fifty point bonus for using all your letters
      if (tilesPlayed == MAX_TILES_IN_HAND)
      {
         cumScore += 50;
      }
      if (isLegalMove)
         return cumScore;
      else
         return -1;
   }
};

int main()
{

   int nPlayer;
   bool success = false;
   Console::WindowHeight = 50;
   do
   {
      Console::WriteLine(
         "Welcome to Scrabble. Enter the number of players (2 to 4).");
      String^ input = Console::ReadLine();
      try
      {
         nPlayer = Int32::Parse(input);
         if (nPlayer < 2 || nPlayer > 4)
            throw gcnew Exception();
         success = true;
      }
      catch(Exception^ )
      {
         success = false;
      }
   } while (! success);

   ScrabbleGame^ game = gcnew ScrabbleGame(nPlayer);
   int firstPlayer = game->PreGame();
   Player^ winner = game->Play(firstPlayer);
   if (winner != nullptr)
      Console::WriteLine("{0} wins!", winner->Name);
   Console::ReadLine();
   return 0;
}
