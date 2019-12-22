// ============ PBCEXTENSION.C ================

// ================= Include =================

#include "pbcextension.h"

// ================= Functions definition ==================

// Functions used to perform graphic rendering of text in the
// console
// To be used through the macro SGRString
// Return a new string which must be freed by the caller, or
// NULL if we couldn't allocate memory for the result string
char* _SGRString(int nbStr, ...) {

  // Init the decoding of the variadic arguments
  va_list argPtr;
  va_start(argPtr, nbStr);

  // Declare a variable to memorize the length of the result string
  // Initialize to 1 for the last '\0'
  unsigned int length = 1;

  // Loop on variadic arugments
  for (int iArg = 0; 
       iArg < nbStr; 
       ++iArg) {

    // Get the next argument
    const char* str = va_arg(argPtr, const char*);

    // Update the length of the result string with the length of the
    // argument
    length += strlen(str);
    
  }

  // Allocate memory and init the result string
  char* sgrStr = (char*)malloc(length);
  if (sgrStr == NULL)
    return NULL;
  sgrStr[0] = '\0';

  // Reset the decoding of the variadic arguments
  va_start(argPtr, nbStr);

  // Loop on variadic arugments
  for (int iArg = 0; 
       iArg < nbStr; 
       ++iArg) {

    // Get the next argument
    const char* str = va_arg(argPtr, const char*);

    // Concatenate the string to the end of the result
    (void)strcat(sgrStr, str);
    
  }

  // Terminate the decoding of the variadic arguments
  va_end(argPtr);

  // Return the result string
  return sgrStr;

}
