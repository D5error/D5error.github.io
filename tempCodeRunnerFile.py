X = np.c_[train.iloc[:, :-1], np.ones((m, 1))]
Y = np.c_[train["y"]]
B = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(Y)
method_3_w = B[0, 0]
method_3_b = B[-1, 0]