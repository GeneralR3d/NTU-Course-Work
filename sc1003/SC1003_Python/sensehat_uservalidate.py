import sense_hat

def main():
    display = sense_hat.SenseHat()
    display.set_rotation(90)
    display.show_message("Welcome to sc1003")

    word = input("what do you want to say? ")
    