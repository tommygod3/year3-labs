import tensorflow as tf
from tensorflow.keras import datasets, models, backend, layers

# Load test data
fashion_mnist = datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

# Manually set class names
class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

# Manually scale image data between 0-1
train_images = train_images / 250
test_images = test_images / 250

# Add fourth dimension (channels) to data 
# Channels = 1 in this dataset as greyscale
img_rows = train_images.shape[1]
img_cols = train_images.shape[2]
if backend.image_data_format() == "channels_first":
    train_images = train_images.reshape(train_images.shape[0], 1, img_rows, img_cols)
    test_images = test_images.reshape(test_images.shape[0], 1, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)
else:
    train_images = train_images.reshape(train_images.shape[0], img_rows, img_cols, 1)
    test_images = test_images.reshape(test_images.shape[0], img_rows, img_cols, 1)
    input_shape = (img_rows, img_cols, 1)

# Load saved model
loaded_model = models.load_model("convolutional.h5")
loaded_model.summary()

test_loss, test_acc = loaded_model.evaluate(test_images,  test_labels, verbose=2)

print('\nTest accuracy:', test_acc)
