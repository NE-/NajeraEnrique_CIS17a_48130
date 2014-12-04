/*
 * File:    FileStream.hpp
 * Author:  Najera Enrique
 * Purpose: Reads and writes
 *          encrypted and readable
 *          files
 *
 * 08 December 2014
 */

#ifndef FILESTREAM_HPP
#define FILESTREAM_HPP

class FileStream
{
    protected:
        bool isOpenSuccess; // Checks if file opened
    public:
        //Mutator Functions
        void setFileOpened(bool fileO)
            { isOpenSuccess = fileO; }

        //Accessor functions
        bool getFileOpened() const
            { return isOpenSuccess; }

        //Functions
        //Takes in filename, content, true/false for encryption
        void readFile(char *, int, bool);     // Reads from file
        void writeFile(char *, int [], bool); // Writes to file
};

#endif // FILESTREAM_HPP

