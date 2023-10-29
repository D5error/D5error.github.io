import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 1
train = pd.read_csv("train.csv")
test = pd.read_csv("test.csv")
train2 = pd.read_csv("train2.csv")
test2 = pd.read_csv("test2.csv")

# 2.1
x_mean = train["x"].mean()
m = len(train["x"])
method_1_w = np.sum(train["y"] * (train["x"] - x_mean)) / (
    np.sum(train["x"] ** 2) - 1 / m * (np.sum(train["x"])) ** 2
)
method_1_b = 1 / m * np.sum(train["y"] - method_1_w * train["x"])

print("method_1_w:", method_1_w)
print("method_1_b:", method_1_b)

# 2.2
m = len(train["x"])
w_now = np.random.random((2, 1))
w_last = w_now
w_change = np.c_[[float("inf")] * 2]
x = np.c_[train["x"], np.ones((m, 1))]
y = np.c_[train["y"]]
eta = 0.002
i = 1
while i < 1000 and w_change.all() > 1e-10:
    gradient = np.c_[np.sum((x.dot(w_now) - y) * x, axis=0)]
    w_now = w_now - eta * gradient
    w_change = abs(w_last - w_now)
    w_last = w_now
    i = i + 1
method_2_w = w_now[0, 0]
method_2_b = w_now[1, 0]

print("method_2_w:", method_2_w)
print("method_2_b:", method_2_b)

# 2.3
m = len(train.iloc[0:, 1])
X = np.c_[train.iloc[:, :-1], np.ones((m, 1))]
Y = np.c_[train["y"]]
B = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(Y)
method_3_w = B[0, 0]
method_3_b = B[-1, 0]

print("method_3_w:", method_3_w)
print("method_3_b:", method_3_b)

# 3
plt.scatter(test["x"], test["y"], color="red", label="real")
plt.plot(
    test["x"], test["x"] * method_1_w + method_1_b, color="aquamarine", label="method 1"
)
plt.plot(test["x"], test["x"] * method_2_w + method_2_b, color="blue", label="method 2")
plt.plot(
    test["x"], test["x"] * method_3_w + method_3_b, color="green", label="method 3"
)
plt.legend()
plt.show()

# 4
m = train2.shape[0]
d = train2.shape[1] - 1
w_now = np.random.random((d + 1, 1))
w_last = w_now
w_change = np.c_[[float("inf")] * (d + 1)]
x = np.c_[train2.iloc[:, :-1], np.ones((m, 1))]
y = np.c_[train2["y"]]
eta = 0.0006
i = 1
while i < 5000 and w_change.all() > 1e-10:
    gradient = np.c_[np.sum((x.dot(w_now) - y) * x, axis=0)]
    w_now = w_now - eta * gradient
    w_change = abs(w_last - w_now)
    w_last = w_now
    i = i + 1
train2_w = w_now
for i in range(len(train2_w) - 1):
    print(f"train2_w{i+1}:", train2_w[i, 0])
print("train2_b:", train2_w[-1, 0])

n = test2.shape[0]
MSE = (
    np.sum(
        (np.c_[test2.iloc[:, :-1], np.ones((n, 1))].dot(train2_w) - np.c_[test2["y"]])
        ** 2,
        axis=0,
    )
    / n
)
print("MSE:", MSE[0])