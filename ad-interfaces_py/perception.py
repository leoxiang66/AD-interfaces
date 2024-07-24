from abc import ABC, abstractmethod
from typing import List
import numpy as np

class BoxCoordinate:
    def __init__(self, x_min: float, y_min: float, x_max: float, y_max: float) -> None:
        self.x_min = x_min
        self.y_min = y_min
        self.x_max = x_max
        self.y_max = y_max

    def __repr__(self) -> str:
        return (f"BoxCoordinate(x_min={self.x_min}, y_min={self.y_min}, "
                f"x_max={self.x_max}, y_max={self.y_max})")

class DetectedBox:
    def __init__(self, coord: BoxCoordinate, conf: float, label: str) -> None:
        self.coord = coord
        self.conf = conf
        self.label = label

    def __repr__(self) -> str:
        return (f"ObjectDetectionOutput(coord={self.coord}, "
                f"conf={self.conf}, label='{self.label}')")

class PerceptionInterface(ABC):
    @abstractmethod
    def object_detection(self, images: List[np.ndarray]) -> List[List[DetectedBox]]:
        pass



