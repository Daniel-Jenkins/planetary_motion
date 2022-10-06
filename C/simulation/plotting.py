from matplotlib import pyplot as plt
import numpy as np


def read_in(filename):
    with open(filename, 'r') as filer:
        full_file = filer.read()

    file_as_str_array = full_file.split('\n\n')
    time_series = []
    for moment in file_as_str_array:
        moment_list = []
        for tt in moment.split('\n'):
            moment_list.append(np.fromstring(tt, dtype=float, sep=' '))
        time_series.append(np.stack(moment_list))

    fig, axis = plt.subplots(1, 1, subplot_kw={"projection": "3d"})

    for moment in time_series:
        for body_num in range(moment.shape[0]):
            position = moment[body_num, :]
            axis.plot(position[0], position[1], position[2], marker='x')
        axis.set_xlim(left=-2, right=2)
        axis.set_ylim(bottom=-2, top=2)
        axis.set_zlim(bottom=-2, top=2)
        plt.pause(0.05)
        axis.cla()

if __name__ == '__main__':
    read_in('./output.dat')
