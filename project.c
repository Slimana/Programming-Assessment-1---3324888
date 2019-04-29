#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cipherfunc (char *msgtext, int key);
void decipherfunc (char *msgtext, int key);

int
main ()
{

  int k;
  int key;
  char msgtext[500];
  char decision[10];
  char rot[] = "Rotation"; //intialising rot as a character type for decision
  char sub[] = "Substitute"; //initialising sub as a character type for decision


  printf
    ("Enter either 'Rotation' for Rotation Cipher or 'Substitute' for Substitution Cipher: "); //prints prompt to choose between Rotation and Substitute

  fgets (decision, sizeof (decision), stdin);

  char *rotation = strpbrk (decision, rot);
  char *substitution = strpbrk (decision, sub);

  if (rotation != NULL)
    {
      char decision2[10];
      char ciph[] = "CI"; //initialses character type for ciph for decision
      char deci[] = "DE"; // initialises character type for deci for decision

      printf ("\nEnter 'CI' to Cipher a text or 'DE' to Decipher a text: "); //print prompt to choose between cipher text and decipher

      fgets (decision2, sizeof (decision2), stdin); //fgets standard input for the the text of decision with limit of 10


      char *ciphr = strpbrk (decision2, ciph);
      char *deciphr = strpbrk (decision2, deci);

      if (ciphr != NULL)
	{

	  printf ("\nInsert text for encryption: ");

	  fgets (msgtext, sizeof (msgtext), stdin); // fgets takes in the input text with a input limit of 400

	  printf ("Enter key: ");

	  scanf ("%d", &k); // Scan in the value of k as a standard input

	  key = 26 - k; // Length of Alphabet minus K will shift to the right

	  printf ("\nCiphered text: ");

	  cipherfunc (msgtext, key); // Calling the cipherfunc to start processing 

	}
      else if (deciphr != NULL)
	{

	  printf ("\nInsert text for decryption: ");

	  fgets (msgtext, sizeof (msgtext), stdin);

	  printf ("Enter Key: ");

	  scanf ("%d", &k);

	  key = 26 - k; // calculates the key by subtracting k from the total length of alphabet, shifting the alphabet to the right 

	  printf ("\nDeciphered text: ");

	  decipherfunc (msgtext, key); // Calls the function decipherfunction to begin calculating the deciphered text 


	}
    }
  else if (substitution != NULL)
    {

      char decision3[10];
      char ciph[] = "CI";
      char deci[] = "DE";

      printf ("\nEnter 'CI' to Cipher a text or 'DE' to Decipher a text: ");

      fgets (decision3, sizeof (decision3), stdin);


      char *ciphr = strpbrk (decision3, ciph);
      char *deciphr = strpbrk (decision3, deci);

      if (ciphr != NULL)
	{

	  char subAlpha[26]; //initialising subAlpha as a character type with limit of 26
	  char plaintext[500]; //initialising plaintext as a character type with a limit of 500

	  printf ("Enter Text for Encryption: ");

	  fgets (plaintext, sizeof (plaintext), stdin);

	  printf ("Enter Substitute Alphabet Key: ");

	  fgets (subAlpha, sizeof (subAlpha), stdin);

	  char ciphertxt[strlen (plaintext)];

	  for (int i = 0; i < strlen (plaintext); i++)
	    {

	      int index;
	      int lettervalue;

	      lettervalue = ((int) plaintext[i]);

	      if (lettervalue >= 97 && lettervalue <= 122)
		{
		  index = lettervalue - 97;
		}
	      else if (lettervalue >= 65 && lettervalue <= 90)
		{
		  index = lettervalue - 65;
		}

	      ciphertxt[i] = subAlpha[index];


	    }

	  printf ("The Encrypted text by substitution is: %s", ciphertxt);
	}
      else if (deciphr != NULL)
	{

	  char subAlpha[26];
	  char ciphertxt[200];
	  char *normAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
	  int i = 0;
	  int j = 0;

	  printf ("Enter Text for Decryption: ");

	  fgets (ciphertxt, sizeof (ciphertxt), stdin);

	  printf ("Enter Substitute Alphabet Key: ");

	  fgets (subAlpha, sizeof (subAlpha), stdin);

	  char plaintxt[strlen (ciphertxt)];

	  for (i = 0; i < strlen (ciphertxt); i++)
	    {

	      int index;
	      int lettervalue;

	      lettervalue = ((int) ciphertxt[i]);

	      if (lettervalue >= 97 && lettervalue <= 122)
		{
		  index = lettervalue - 97;
		}
	      else if (lettervalue >= 65 && lettervalue <= 90)
		{
		  index = lettervalue - 65;
		}

	      if (index < 0)
		{
		  plaintxt[i] = ' ';
		}

	      for (j = 0; j < 25; j++)
		{
		  int index2;
		  int subletterval;

		  subletterval = ((int) subAlpha[j]);

		  index2 = subletterval - 65;

		  if (index == index2)
		    {
		      plaintxt[i] = normAlpha[j];
		    }

		}

	    }

	  printf ("The Decrypted text by substitution is: %s", plaintxt);
	}
    }
}

void
cipherfunc (char *msgtext, int key)
{

  int i = 0;
  int lettervalue;
  int ciphervalue;
  char cipher;

  while (msgtext[i] != '\0' && strlen (msgtext) - 1 > i)
    {

      if (msgtext[i] >= 97 && msgtext[i] <= 122)
	{

	  lettervalue = msgtext[i] - 97;
	}
      else if (msgtext[i] >= 65 && msgtext[i] <= 90)
	{

	  lettervalue = msgtext[i] - 65;

	}

      ciphervalue = (lettervalue + key) % 26 + 65;

      cipher = ciphervalue;

      printf ("%c", cipher);

      i++;
    }

}

void
decipherfunc (char *msgtext, int key)
{

  int i = 0;
  int lettervalue;
  int deciphervalue;
  int LminusK;
  char decipher;

  while (msgtext[i] != '\0' && strlen (msgtext) - 1 > i) //while loop until \0 is given and if string length exeeded
    {

      if (msgtext[i] >= 97 && msgtext[i] <= 122) //lowercase range to uppercase range 
	{
	  lettervalue = msgtext[i] - 97; //ASCII table (32 to change to uppercase then return to 0 with 65)
	}
      else if (msgtext[i] >= 65 && msgtext[i] <= 90) // letter is in uppercase range
	{
	  lettervalue = msgtext[i] - 65; //lettervalue given by subtracting 65 to get A=0
	}

      LminusK = lettervalue - key;

      if (LminusK < 0) // if the letter minus key is negative its modulus with 26 has undefined behaviour and changes result
	{
	  LminusK = LminusK + 26; //26 added to change from negative to positive
	}

      deciphervalue = LminusK % 26 + 65; //equation to decipher text

      decipher = deciphervalue;

      printf ("%c", decipher);

      i++;
    }
}
