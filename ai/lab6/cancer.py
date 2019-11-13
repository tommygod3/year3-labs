from sklearn.neural_network import MLPClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split

dataset = load_breast_cancer()


results = 0

for i in range(100):
    data_train, data_test, label_train, label_test = train_test_split(dataset.data, dataset.target, train_size=0.6)
    clf = MLPClassifier(hidden_layer_sizes=(15, 5))
    clf.fit(data_train, label_train)
    results += clf.score(data_test, label_test)/100

print(results)