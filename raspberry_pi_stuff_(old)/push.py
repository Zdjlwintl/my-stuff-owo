import time
import RPi.GPIO as GPIO

BUTTON = 26
LED = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(BUTTON, GPIO.IN)
GPIO.setup(LED, GPIO.OUT)

while True:
    if GPIO.input(BUTTON) == GPIO.HIGH:
        GPIO.output(LED, GPIO.HIGH)
    else:
        GPIO.output(LED, GPIO.LOW)

GPIO.cleanup
