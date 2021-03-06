from __future__ import annotations

import pytest

from src.parse import parse_arguments


@pytest.mark.parametrize(
    "args",
    [
        ["-l"],
        ["-l", "str"],
        ["-l", "-1"],
        ["-c"],
        ["-c", "str"],
        ["-c", "-1"],
        ["-r"],
        ["-r", "1"],
        ["-r", "2", "1"],
        ["-d"],
        ["-d", "no_such_dir"],
        ["--invalid"],
    ],
)
def test_parse_arguments_error(args: list[str]) -> None:
    with pytest.raises(SystemExit):
        parse_arguments(args)


def test_parse_arguments_normal() -> None:
    args = ["-l", "42", "-c", "24", "-r", "1", "2", "-d", "../push_swap"]
    ret = parse_arguments(args)
    assert ret.len == 42
    assert ret.count == 24
    assert ret.range[0] == 1
    assert ret.range[1] == 2
    assert str(ret.dir) == "../push_swap"
