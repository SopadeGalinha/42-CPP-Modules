/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:55:55 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 22:55:55 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static bool check_args(const std::string& arg);
static void dialogue(std::string& level);
static void clerk_dialogue(std::string& line);
static void harl_dialogue(Harl &harl, std::string& level);

int main(int argc, char *argv[]) {
    if (argc > 2 || (argv[1] && !check_args(argv[1]))) {
        std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return (1);
    }
    
    if (argc == 2) {
        std::string filter(argv[1]);
        dialogue(filter);
    } else {
        std::string no_filter("DEBUG");
        dialogue(no_filter);
    }
    std::cout << "[CLERK] (to another Clerk)" << std::endl;
    std::cout << "Thank God" << std::endl;
    std::cout << std::endl;
    return (0);
}

static bool check_args(const std::string& arg)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (arg == levels[i])
            return (true);
    }
    return (false);
}

static void dialogue(std::string& level) {
    Harl harl;

    harl.setFilter(level);
    std::string harl_levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
    std::string clerk_lines[5] = {
        "Oh! Yes, sir. How can I help you now?",
        "Certainly, sir! We offer additional toppings for an extra charge. I'll make sure to add more bacon to your order.",
        "I apologize for the inconvenience, sir, but all our burguers come with the exact same amount of bacon.",
        "I'm sorry, sir, but I'm afraid I can't do that.",
        "I'll call them for y..."   
    };

    switch (harl.getFilter()) {
        case INFO:
            clerk_lines[1] = "Sir? Uh... would you like to pay for some more bacon, is that it?";
            break;
        case WARNING:
            clerk_lines[1] = "Sir? Uh... would you like to pay for some more bacon, is that it?";
            clerk_lines[2] = "Uh... can I help you with anything else?";
            clerk_lines[3] = "Sir, please, calm down!";
            break;
        case ERROR:
            clerk_lines[1] = "Sir? Did you hear me?";
            clerk_lines[2] = "Uh... can I help you with anything else?";
            clerk_lines[3] = "Okay then, uh... have a nice dinner, then.";
            clerk_lines[4] = "What the fu...?!";
            break;
        default:
            break;
    };

    // Test different complaint levels
    for (int i = 0; i < 5; i++)
    {
        clerk_dialogue(clerk_lines[i]);
        harl_dialogue(harl, harl_levels[i]);
    }
    return ;
}

static void clerk_dialogue(std::string& line) {
    std::cout << "[CLERK]" << std::endl;
    std::cout << line << std::endl;
    std::cout << std::endl;
    return;
}

static void harl_dialogue(Harl &harl, std::string& level) {
    std::cout << "[HARL]" << std::endl;
    harl.complain(level);
    std::cout << std::endl;
    return;
}
