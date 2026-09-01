var minMoves = function(classroom, energy) {
    const n = classroom.length;
    const m = classroom[0].length;

    let sr = 0, sc = 0;
    let litterCount = 0;

    const litterId = Array.from(
        { length: n },
        () => Array(m).fill(-1)
    );

    // Find start and number every litter
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < m; c++) {
            if (classroom[r][c] === 'S') {
                sr = r;
                sc = c;
            }

            if (classroom[r][c] === 'L') {
                litterId[r][c] = litterCount++;
            }
        }
    }

    const fullMask = (1 << litterCount) - 1;

    if (fullMask === 0) return 0;

    /*
        best[state] = maximum energy with which
        we have reached (r, c, mask)
    */

    const totalStates = n * m * (1 << litterCount);

    const best = new Int16Array(totalStates);
    best.fill(-1);

    // Encode (r, c, mask) into one number
    const encode = (r, c, mask) =>
        ((r * m + c) << litterCount) | mask;

    const startState = encode(sr, sc, 0);

    best[startState] = energy;

    /*
        Queue stores:
        [r, c, mask, energy, steps]

        Using arrays of numbers instead of nested arrays
        reduces overhead.
    */

    const qr = [];
    const qc = [];
    const qm = [];
    const qe = [];
    const qs = [];

    let head = 0;

    qr.push(sr);
    qc.push(sc);
    qm.push(0);
    qe.push(energy);
    qs.push(0);

    const dr = [0, 1, 0, -1];
    const dc = [1, 0, -1, 0];

    while (head < qr.length) {

        const r = qr[head];
        const c = qc[head];
        const mask = qm[head];
        const e = qe[head];
        const steps = qs[head];

        head++;

        if (mask === fullMask) {
            return steps;
        }

        if (e === 0) {
            continue;
        }

        for (let d = 0; d < 4; d++) {

            const nr = r + dr[d];
            const nc = c + dc[d];

            if (
                nr < 0 ||
                nr >= n ||
                nc < 0 ||
                nc >= m
            ) {
                continue;
            }

            if (classroom[nr][nc] === 'X') {
                continue;
            }

            let newEnergy = e - 1;
            let newMask = mask;

            // Litter
            if (classroom[nr][nc] === 'L') {
                newMask |= (1 << litterId[nr][nc]);
            }

            // Recharge
            if (classroom[nr][nc] === 'R') {
                newEnergy = energy;
            }

            const state = encode(nr, nc, newMask);

            /*
                If we've already reached this exact
                (position + mask) with >= energy,
                this state is useless.
            */
            if (best[state] >= newEnergy) {
                continue;
            }

            best[state] = newEnergy;

            qr.push(nr);
            qc.push(nc);
            qm.push(newMask);
            qe.push(newEnergy);
            qs.push(steps + 1);
        }
    }

    return -1;
};