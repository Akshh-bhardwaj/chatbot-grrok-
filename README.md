Grok - A Simple Chatbot in C

Grok is a simple chatbot written in C that responds to user input with jokes, facts, greetings, and basic file operations. It provides interactive responses and can read, write, and append to files.

Features

Responds to greetings ("hello", "hi", "hey").

Tells random jokes.

Shares interesting facts.

Reads content from a file.

Writes content to a file.

Appends content to a file.

Provides the current time.

Installation

Clone the repository:

git clone https://github.com/Akshh-bhardwaj/chatbot-grrok-/tree/main
cd chatbot-grrok-

Compile the program:

gcc chatbot.c -o grok

Run the chatbot:

./grok

Usage

When running Grok, type commands into the console:

hello, hi, hey - Receive a friendly greeting.

joke - Hear a random joke.

fact - Learn an interesting fact.

time - Get the current time.

read <filename> - Read and display the contents of a file.

write <filename> "<content>" - Write content to a file.

append <filename> "<content>" - Append content to a file.

bye - Exit the chatbot.

Example Interaction

Grok: Hello! Type 'help' to see what I can do, or 'bye' to exit.
You: hi
Grok: Hey there! How’s your day going?
You: joke
Grok: Why did the scarecrow win an award? Because he was outstanding in his field!
You: fact
Grok: Honey never spoils.
You: bye
Grok: Goodbye! Have a great day!

Contributions

Feel free to fork the repository and submit pull requests with improvements or new features!

License

This project is open-source and available under the MIT License.

Repository Link

GitHub Repository

