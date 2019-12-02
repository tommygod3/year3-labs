import os

import urllib.request
import cv2
import tensorflow as tf
from tensorflow.keras import models, backend, layers
import numpy

# Manually set class names
class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

urllib.request.urlretrieve("https://www.cdn-docs-cft.com/docs/img/gross/3348/michael-schumacher-t-shirt-racing.jpg", "shirt.jpg")

img_rows = 28
img_cols = 28

shirt = cv2.imread("shirt.jpg")

gray_shirt = cv2.cvtColor(shirt, cv2.COLOR_BGR2GRAY)
scaled_shirt = cv2.resize(gray_shirt, dsize=(img_rows, img_cols), interpolation=cv2.INTER_CUBIC)

if backend.image_data_format() == "channels_first":
    test_images = scaled_shirt.reshape(1, 1, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)
else:
    test_images = scaled_shirt.reshape(1, img_rows, img_cols, 1)
    input_shape = (img_rows, img_cols, 1)

# Load saved model
loaded_model = models.load_model("convolutional.h5")
loaded_model.summary()

predictions = loaded_model.predict(test_images)

print('\n Predictions:', class_names[numpy.argmax(predictions)])
