import connexion
import six

from swagger_server.models.number import Number  # noqa: E501
from swagger_server.models.pair import Pair  # noqa: E501
from swagger_server import util


def add_nums(body):  # noqa: E501
    """add two numbers from pair

    add two numbers from pair # noqa: E501

    :param body: Add two numbers from pair
    :type body: dict | bytes

    :rtype: Number
    """
    if connexion.request.is_json:
        body = Pair.from_dict(connexion.request.get_json())  # noqa: E501
    return Number(body._number1 + body._number2)


def div_nums(body):  # noqa: E501
    """divide two numbers from pair

    divide two numbers from pair # noqa: E501

    :param body: Multiply two numbers from pair
    :type body: dict | bytes

    :rtype: Number
    """
    if connexion.request.is_json:
        body = Pair.from_dict(connexion.request.get_json())  # noqa: E501
    return Number(body._number1 // body._number2)



def multi_nums(body):  # noqa: E501
    """multiply two numbers from pair

    multiply two numbers from pair # noqa: E501

    :param body: Multiply two numbers from pair
    :type body: dict | bytes

    :rtype: Number
    """
    if connexion.request.is_json:
        body = Pair.from_dict(connexion.request.get_json())  # noqa: E501
    return Number(body._number1 * body._number2)


def sub_nums(body):  # noqa: E501
    """subtract two numbers from pair

    subtract two numbers from pair # noqa: E501

    :param body: Subtract two numbers from pair
    :type body: dict | bytes

    :rtype: Number
    """
    if connexion.request.is_json:
        body = Pair.from_dict(connexion.request.get_json())  # noqa: E501
    return Number(body._number1 - body._number2)

