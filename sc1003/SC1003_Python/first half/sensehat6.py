import sense_hat,time

display = sense_hat.SenseHat()

while True:
    pitch = display.get_orientation()['pitch']
    roll = display.get_orientation()['roll']
    print(pitch,roll,sep="  ")
    time.sleep(0.05)