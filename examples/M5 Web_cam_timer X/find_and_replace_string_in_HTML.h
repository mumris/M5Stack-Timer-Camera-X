char output[25000];
char input[25000];
char pattern[] = "password";
int replace_or_insert_substring(int from_index, bool replaceit, const char inputstr[], const char pattern[], const char newsubstr[], char output[]) 
// false =just add at end of pattern position, true =replace pattern with a new one.
  {
      
        long int i = from_index, j = 0, flag = 0, start = 0, start1 = 0, stopp = 0, untill = 0;
        
        // check whether the pattern to be replaced is present 
        while (inputstr[i] != '\0')
        {
                if (inputstr[i] == pattern[j]) 
                {
                        if (!flag) {start = i; start1 = i;}
                        j++;
                        if (pattern[j] == '\0') break;
                        flag = 1;
                } 
                else 
                {
                        flag = start = start1 = j = 0;
                }
                i++;  // start is pattern beginning position
        }
        stopp = i+1; //stopp shows '\0' position of end pattern
        if(!replaceit) start1 = stopp;
        if (pattern[j] == '\0' && flag)
        {
                for (i = 0; i < start1; i++)
                        output[i] = inputstr[i];
        // replace pattern with another string 
                for (j = 0; j < strlen(newsubstr); j++) 
                {
                        output[i] = newsubstr[j];
                        i++;
                }

       // copy remaining portion of the input string "inputstr[]" 
     
          j = stopp;
          while (inputstr[j] != '\0')        
          {
          output[i++] = inputstr[j++];
          }                   
          // print the final string 
          output[i] = '\0';        
        } 
        else 
        {
                //Serial.printf("%s pattern is not found in string\n", pattern);
                stopp = -1;
        }
  return stopp;
  }

  ////////////////////////
void  replace_multiple_str(const char index_html0[], char input[], const char pattern[], const char password[], char output[])  
    {    
       int ii=0;          
       std::strcpy(input, index_html0); 
       while (ii>=0)
       {
       if (ii>=0) ii = replace_or_insert_substring(ii, true, input, pattern, password, output); //index_html[]           
       std::strcpy(input, output);         
       //Serial.printf("Position is: %d\n", ii);  
       }
    }
        
///////////////////////////
