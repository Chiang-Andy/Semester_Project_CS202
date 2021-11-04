# Semester_Project_CS202

()Program Flow
    Start: Present start menu
    If user selects quit, exit program
    Else
        Request filename from user
        Open file specified by filename
        If file does not exist or file is not wav file
        display error message and goto start
    else
        read file metadata 
    (1) display metadata to user
        present user with processor menu
        If user selects processor option
            request output filename
            run processor
            save file
            goto Start


()File Metadata
The data to be displayed in step (1):

    filename

    sample rate

    bits per sample

    stereo or mono


()Required Processors
The following are the processes to be implemented

normalization

    Algorithm: The largest sample value in the data is found, and then the data is scaled so that that value is the maximum possible value. This maximizes the amplitude of the final waveform.

    Example for floating-point data

        Original data: n = {0,0.2,0.4,0,-0.3}

        Largest absolute value: 0.4, so scaling value s = 1/0.4 = 2.5

        Scaled result: n_scaled = {0, 0.5,1,0,-0.75}

echo

    Algorithm: Samples are copied, scaled, and added to later locations in the sample buffer to create an echo effect.

gain adjustment

    Algorithm: Samples are multiplied by a scaling factor that raises or lowers the overall amplitude of the wave file

()Required Processors
The challenge-level application includes all the processors from the basic level. In addition, it must include the following processors:

low-pass filter
    Remove high frequency components from the signal

compression / limiting
    The dynamic range of the signal is compressed using a non-linear map of input to output. This is commonly used to limit loud peaks in the sound, and gives an overall impression of higher volume.






