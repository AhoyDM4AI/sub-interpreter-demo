from multiprocessing import Pool
from joblib import Parallel, delayed

def f(x):
    a=0
    for i in range(500000000):
        a = a+1
    return a*x


if __name__ == '__main__':
    with Pool(4) as p:
        print(p.map(f, [1, 2, 3, 4, 5]))
    
    # parallel_obj = Parallel(n_jobs=-1, verbose=0, backend='loky', timeout=500)
    # out = parallel_obj(delayed(f)(i) for i in range(5))
    # print(out)