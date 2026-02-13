import time
import RPi.GPIO as GPIO

LED_PIN = 17
OTHER_LED = 27

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(OTHER_LED, GPIO.OUT)


while True:
    GPIO.output(LED_PIN, GPIO.HIGH)
    GPIO.output(OTHER_LED, GPIO.LOW)
    time.sleep(1)
    GPIO.output(LED_PIN, GPIO.LOW)
    GPIO.output(OTHER_LED, GPIO.HIGH)
    time.sleep(1)

GPIO.cleanup()
