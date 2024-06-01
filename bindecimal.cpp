#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

std::string binarify(int);
int         get_max(std::vector<std::string>);

int
main(int argc, char **argv)
{
    std::vector<std::string> messages;

    if ( argc == 1 )
    {
        std::fprintf(stderr, "%s", argv[0]);
        // std::cout << "BinDecimal printer" << std::endl
        //           << "Call program with argument" << std::endl;

        messages = {
            "And we've got work in the morning; But it's nearly 5AM; Is this "
            "really what we envisaged?; We won't be 21 again;",
            "So wake me up when it's all over; When I'm wiser and I'm older; "
            "All this time I was finding myself, and I; Didn't know I was "
            "lost",
            "See the stone set in your eyes; See the thorn twist in your "
            "side; I'll wait for you",
            "I had all and then most of you; Some and now none of you; Take "
            "me back to the night we met",
            "Now we're there and we've only just begun; This will be our "
            "year; Took a long time to come",
            "You tell me, \"Hit this and let's go; Blow the smoke right "
            "through the window\"; 'Cause this is all we know",
            "हमने इस बंजर भूमि पर जब ज्ञान का दीप जलाया था।",
        };
    }

    else
    {
        // message = argv[1];

        // if ( argc > 2 ) {
        //   for ( int i = 2; i < argc; i++ ) {
        //     message.append(" ");
        //     message.append(argv[i]);
        //   }
        // }
    }

    for ( std::string message : messages )
    {
        std::string              block  = "\u2588";
        std::string              blocks = "\u2588\u2588";
        std::string              dot    = "\u2022";
        std::vector<int>         dec_vec;
        std::vector<std::string> bin_vec;

        for ( char c : message )
        {
            int num = c;

            dec_vec.push_back(num);
            bin_vec.push_back(binarify(num));
        }

        unsigned int max = get_max(bin_vec);

        for ( std::string &bin : bin_vec )
        {
            if ( bin.size() < max )
            {
                while ( bin.size() != max )
                {
                    bin.append("x");
                }
            }

            std::reverse(bin.begin(), bin.end());
        }

        for ( char c : message )
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;

        for ( unsigned int j = 0; j < max; j++ )
        {
            for ( unsigned int i = 0; i < message.size(); i++ )
            {
                // std::cout << message[i] << ": ";

                std::cout << (bin_vec[i][j] == 'x' ? "  " : blocks);
            }

            std::cout << std::endl;
        }
    }

    std::string      block  = "\u2588";
    std::string      blocks = "\u2588\u2588";
    std::string      dot    = "\u2022";
    std::vector<int> dec_vec
        = { 224, 164, 185, 224, 164, 174, 224, 164, 168, 224, 165, 135,
            32,  224, 164, 135, 224, 164, 184, 32,  224, 164, 172, 224,
            164, 130, 224, 164, 156, 224, 164, 176, 32,  224, 164, 173,
            224, 165, 130, 224, 164, 174, 224, 164, 191, 32,  224, 164,
            170, 224, 164, 176, 32,  224, 164, 156, 224, 164, 172, 32,
            224, 164, 156, 224, 165, 141, 224, 164, 158, 224, 164, 190,
            224, 164, 168, 32,  224, 164, 149, 224, 164, 190, 32,  224,
            164, 166, 224, 165, 128, 224, 164, 170, 32,  224, 164, 156,
            224, 164, 178, 224, 164, 190, 224, 164, 175, 224, 164, 190,
            32,  224, 164, 165, 224, 164, 190, 224, 165, 164 };
    std::vector<std::string> bin_vec;

    for ( int n : dec_vec )
    {
        bin_vec.push_back(binarify(n));
    }

    unsigned int max = get_max(bin_vec);

    for ( std::string &bin : bin_vec )
    {
        if ( bin.size() < max )
        {
            while ( bin.size() != max )
            {
                bin.append("x");
            }
        }

        std::reverse(bin.begin(), bin.end());
    }

    std::cout << std::endl;

    for ( unsigned int j = 0; j < max; j++ )
    {
        for ( unsigned int i = 0; i < dec_vec.size(); i++ )
        {
            // std::cout << message[i] << ": ";

            std::cout << (bin_vec[i][j] == 'x' ? "  " : blocks);
        }

        std::cout << std::endl;
    }
    return 0;
}

std::string
binarify(int num)
{
    std::string binary = "";

    while ( num > 0 )
    {
        if ( num % 2 == 0 )
        {
            binary.append("x");
        }
        else
        {
            binary.append("o");
        }

        num /= 2;
    }

    return binary;
}

int
get_max(std::vector<std::string> bin_vec)
{
    int max = -std::numeric_limits<int>::infinity();

    for ( std::string bin : bin_vec )
    {
        if ( ( int ) bin.size() > max )
        {
            max = bin.size();
        }
    }

    return max;
}
