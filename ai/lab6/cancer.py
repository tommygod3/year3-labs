from sklearn.neural_network import MLPClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn import preprocessing
from sklearn.decomposition import PCA

dataset = load_breast_cancer()

# Split data and labels into train / test
train_data, test_data, train_label, test_label = train_test_split(dataset.data, dataset.target, train_size=0.6)

# Scaling
train_data = preprocessing.scale(train_data)
test_data = preprocessing.scale(test_data)

# PCA on training data
pca = PCA(n_components=10)
pca_train_data = pca.fit_transform(train_data)

# Do I PCA the test data also?? Otherwise the dimensionality does not match
pca_test_data = pca.fit_transform(test_data)

clf = MLPClassifier(hidden_layer_sizes=(15, 5), solver="lbfgs")
clf.fit(train_data, train_label)
print(f"No PCA: {clf.score(test_data, test_label)}")

pca_clf = MLPClassifier(hidden_layer_sizes=(5), solver="lbfgs")
pca_clf.fit(pca_train_data, train_label)
print(f"PCA: {pca_clf.score(pca_test_data, test_label)}")
