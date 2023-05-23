import re
import random

# Global variables
global R_EATING
R_EATING = "I don't like eating anything because I'm not a bot obviously!"
global R_ADVICE
R_ADVICE = "If I were you, I would go to the internet and type exactly what you wrote there!"

def message_probability(user_message, recognised_words, single_response=False, required_words=[]):

    message_certainity = 0
    has_required_words = True

    # Count the number of recognized words in the user's message
    for word in user_message:
        if word in recognised_words:
            message_certainity += 1

    # Calculate the probability as a percentage
    percentage = float(message_certainity) / float(len(recognised_words))

    # Check if the message contains all the required words or if it's a single response
    for word in required_words:
        if word not in user_message:
            has_required_words = False
            break

    if has_required_words or single_response:
        return int(percentage * 100)
    else:
        return 0


def check_all_messages(message):

    highest_prob_list = {}

    def response(bot_response, list_of_words, single_response=False, required_words=[]):
        nonlocal highest_prob_list
        highest_prob_list[bot_response] = message_probability(message, list_of_words, single_response, required_words)

    # Define the possible bot responses and their corresponding recognized words and requirements
    response('Hello!', ['hello', 'hi', 'hey', 'sup', 'heyo'], single_response=True)
    response('See you!', ['bye', 'goodbye'], single_response=True)
    response('I\'m doing fine, and you?', ['how', 'are', 'you', 'doing'], required_words=['how'])
    response('You\'re welcome!', ['thank', 'thanks'], single_response=True)
    response('Thank you!', ['i', 'love', 'code', 'palace'], required_words=['code', 'palace'])
    response(R_ADVICE, ['give', 'advice'], required_words=['advice'])
    response(R_EATING, ['what', 'you', 'eat'], required_words=['you', 'eat'])

    # Find the best matching bot response with the highest probability
    best_match = max(highest_prob_list, key=highest_prob_list.get)

    return unknown() if highest_prob_list[best_match] < 1 else best_match


def unknown():
    response = [
        'Could you please re-phrase that?',
        '...',
        'Sounds about right',
        'What does that mean?'
    ][random.randrange(4)]
    return response


def get_response(user_input):
    split_message = re.split(r'\s+|[,;?!.-]\s*', user_input.lower())
    response = check_all_messages(split_message)
    return response


# Testing the response system
while True:
    print('Bot: ' + get_response(input('You: ')))
