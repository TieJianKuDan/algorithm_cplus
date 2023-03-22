src = ${wildcard src/*.cpp}
obj = ${patsubst src/%.cpp, obj/%.obj, ${src}}
out = ${patsubst obj/%.obj, out/%.exe, ${obj}}
_out = ${patsubst out/%.exe, %.exe, ${out}}
_obj = ${patsubst obj/%.obj, %.obj, ${obj}}

ALL : ${out}

out/%.exe : obj/%.obj
	g++ $< -o $@
obj/%.obj : src/%.cpp
	g++ -c $< -o $@ -g -Wall -O0

clean:
	del /Q /F /S ${_out} ${_obj}

.PHONY: clean ALL

.PRECIOUS: obj/%.obj