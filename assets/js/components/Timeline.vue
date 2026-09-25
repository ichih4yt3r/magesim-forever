<template>
    <div class="timeline">
        <div class="graph">
            <Line v-if="chartData" :data="chartData" :options="chartOptions" :plugins="chartPlugins" />
        </div>
        <div class="events">
            <div class="timestamps">
                <div class="title">Effect (uptime %)</div>
                <div class="times">
                    <div class="time" v-for="time in times" :style="timeStyle(time)">
                        {{ formatTime(time) }}
                    </div>
                </div>
            </div>
            <div class="items">
                <div class="item" v-for="event in events">
                    <div class="title" :style="{color: event.color}">
                        {{ event.title }}
                        <template v-if="event.hasOwnProperty('uptime')">
                            ({{ event.uptime }}%)
                        </template>
                    </div>
                    <div class="times">
                        <div class="bar" v-for="item in event.events" :style="barStyle(item, event.color)"></div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
    import { Line } from "vue-chartjs";
    import {
        Chart as ChartJS,
        LineController,
        LineElement,
        PointElement,
        LinearScale,
        Legend,
        Filler,
    } from "chart.js";

    ChartJS.register(LineController, LineElement, PointElement, LinearScale, Legend, Filler);

    const alignPlot = {
        id: "alignPlot",
        afterLayout(chart) {
            const x = chart.scales.x;
            let plotLeftEdge = 0;
            let plotRightEdge = chart.width;

            Object.values(chart.scales).forEach((scale) => {
                if (!scale || scale === x || scale.isHorizontal())
                    return;
                if (scale.options.position === "right")
                    plotRightEdge = Math.min(plotRightEdge, scale.left);
                else
                    plotLeftEdge = Math.max(plotLeftEdge, scale.right);
            });

            chart.chartArea.left = plotLeftEdge;
            chart.chartArea.right = plotRightEdge;
            if (x) {
                x.left = plotLeftEdge;
                x.right = plotRightEdge;
                x.configure();
            }

            const timeline = chart.canvas.closest(".timeline");
            if (timeline) {
                timeline.style.setProperty("--plot-left", plotLeftEdge + "px");
                timeline.style.setProperty("--plot-right", (chart.width - plotRightEdge) + "px");
            }
        },
    };

    export default {
        components: { Line },

        props: ["result"],

        data() {
            return {
                chartPlugins: [alignPlot],
                cds: [
                    { title: "Mana Tide", color: "#05c" },
                    { title: "Innervate", color: "#05c" },
                    { title: "Evocation", color: "#05c" },
                    { title: "Flame Cap", color: "rgba(200,120,70)" },
                    { title: "Bloodlust", color: "rgba(220,70,70)" },
                    { title: "Icy Veins", color: "rgba(85,170,255)" },
                    { title: "Berserking", color: "rgba(200,80,80)" },
                    { title: "Blood Fury", color: "rgba(180,60,40)" },
                    { title: "Read Ley Line", color: "rgba(120,160,220)" },
                    { title: "Eureka", color: "rgba(220,180,70)" },
                    { title: "Arcane Power", color: "#48f" },
                    { title: "Missile Barrage", color: "#c6f" },
                    { title: "Combustion", color: "#f84" },
                    { title: "Power Infusion", color: "#dd0" },
                    { title: "Lightweave", color: "#823978" },
                    { title: "Incanter's Absorption", color: "#777" },
                    { title: "Black Magic", color: "#89d1d0" },
                    { title: "Hyperspeed Acceleration", color: "#206f80" },
                    { title: "Speed", color: "#d82" },
                    { title: "Wild Magic", color: "#cc6" },
                    { title: "Praxis", color: "#690042" },
                    { title: "Pushing the Limit", color: "#fcd3e1" },
                    { title: "Quad Core", color: "#ddd" },
                    { title: "Arcane Madness", color: "#ddd" },
                    { title: "Frostforged Sage", color: "#ddd" },
                ],
                trinkets: [
                    { title: "Nevermelting Ice Crystal", color: "#ddd" },
                    { title: "Revitalized", color: "#ddd" },
                    { title: "Twilight Flames", color: "#ddd" },
                    { title: "Surge of Power", color: "#ddd" },
                    { title: "Siphoned Power", color: "#ddd" },
                    { title: "Cultivated Power", color: "#ddd" },
                    { title: "Energized", color: "#ddd" },
                    { title: "Volatility", color: "#ddd" },
                    { title: "Celerity", color: "#ddd" },
                    { title: "Hospitality", color: "#ddd" },
                    { title: "Scale of Fates", color: "#ddd" },
                    { title: "Show of Faith", color: "#ddd" },
                    { title: "Flame of the Heavens", color: "#ddd" },
                    { title: "Living Flame", color: "#ddd" },
                    { title: "Pandora's Plea", color: "#ddd" },
                    { title: "Memories of Love", color: "#55d" },
                    { title: "Alacrity of the Elements", color: "#ddd" },
                    { title: "Dying Curse", color: "#5b5" },
                    { title: "Now is the Time!", color: "#ddd" },
                    { title: "Elusive Power", color: "#ddd" },
                    { title: "Embrace of the Spider", color: "#777" },
                    { title: "Twilight Serpent", color: "#ddd" },
                    { title: "Infinite Power", color: "#ddd" },
                    { title: "Tome of Arcane Phenomena", color: "#ddd" },
                    { title: "Argent Valor", color: "#ddd" },
                    { title: "Mark of the War Prisoner", color: "#ddd" },
                    { title: "Forge Ember", color: "#ddd" },
                    { title: "Mana Surge", color: "#2da" },
                    { title: "Mana Surges", color: "#2da" },
                    { title: "Fel Infusion", color: "#b24" },
                    { title: "Mojo Madness", color: "#d22" },
                    { title: "Insight of the Ashtongue", color: "#cc8" },
                    { title: "Power Circle", color: "#a2a" },
                ],
                mana_gains: [
                    { title: "Mana Gem", color: "rgba(85,255,85)" },
                    { title: "Mana Potion", color: "#00d" },
                    { title: "Arcane Torrent", color: "#bbd" },
                    { title: "Sliver of Pure Ice", color: "rgba(85,255,85)" },
                ]
            }
        },

        computed: {
            chartData() {
                var mana = [];
                var log = this.result.log;
                for (var i = 0; i < log.length; i++) {
                    if (log[i].t < 0 || log[i].unit != "Player")
                        continue;
                    var last = mana[mana.length - 1];
                    if (last && log[i].t <= last.x)
                        last.y = log[i].mana_percent;
                    else
                        mana.push({ x: log[i].t, y: log[i].mana_percent });
                }
                var lastPlayer = null;
                for (var i = log.length - 1; i >= 0; i--) {
                    if (log[i].unit == "Player") {
                        lastPlayer = log[i];
                        break;
                    }
                }
                mana.push({ x: this.result.t, y: lastPlayer ? lastPlayer.mana_percent : 0 });

                var dps = [{ x: 0, y: 0 }];
                for (var i = 0; i < log.length; i++) {
                    if (log[i].type == 3 && log[i].t)
                        dps.push({ x: log[i].t, y: log[i].dmg / log[i].t });
                }
                dps.push({ x: this.result.t, y: this.result.dps });

                return {
                    datasets: [
                        {
                            data: mana,
                            borderColor: "#08f",
                            borderWidth: 1,
                            pointRadius: 0,
                            hitRadius: 0,
                            stepped: true,
                            label: "Mana",
                        },
                        {
                            data: dps,
                            borderColor: "#f00",
                            borderWidth: 1,
                            pointRadius: 0,
                            label: "DPS",
                            fill: false,
                            yAxisID: "dps",
                        },
                    ],
                };
            },

            chartOptions() {
                return {
                    responsive: true,
                    maintainAspectRatio: false,
                    animation: false,
                    color: "rgba(255,255,255,0.75)",
                    plugins: {
                        legend: {
                            display: true,
                            labels: {
                                filter: function(item) {
                                    return item.text != "";
                                },
                            },
                        },
                        tooltip: {
                            enabled: false,
                        },
                    },
                    elements: {
                        line: {
                            tension: 0,
                        },
                    },
                    scales: {
                        x: {
                            type: "linear",
                            min: 0,
                            max: this.result.t,
                            bounds: "data",
                            offset: false,
                            title: {
                                display: true,
                                text: "Time (s)",
                            },
                            grid: {
                                color: "rgba(120,140,240,0.1)",
                            },
                        },
                        y: {
                            type: "linear",
                            beginAtZero: true,
                            title: {
                                display: true,
                                text: "Mana (%)",
                            },
                            grid: {
                                color: "rgba(120,140,240,0.4)",
                            },
                        },
                        dps: {
                            type: "linear",
                            position: "left",
                            beginAtZero: true,
                            title: {
                                display: true,
                                text: "DPS",
                            },
                            grid: {
                                drawOnChartArea: false,
                            },
                        },
                    },
                };
            },

            times() {
                var times = [];
                var steps = [1,2,5,10,15,20,30,40,60,90,120];
                var step = 150;
                var div = this.result.t / 20;

                for (var i=0; i<steps.length; i++) {
                    if (div < steps[i]) {
                        step = steps[i];
                        break;
                    }
                }

                times.push(0);
                for (var i=step; i<this.result.t; i+= step) {
                    times.push(i);
                }
                times.push(this.result.t);

                return times;
            },

            events() {
                var self = this;
                var events = [];
                var event, start, end, uptime;
                var logs;

                // CDs
                for (var i=0; i<this.cds.length; i++) {
                    var r = new RegExp(this.cds[i].title+"( \\\([0-9]+\\\))?\\\.");
                    logs = _.filter(this.result.log, l => l.type == 5 && l.text.match(r));
                    if (logs.length) {
                        uptime = 0;
                        event = _.clone(this.cds[i]);
                        event.events = [];
                        for (var j = 0; j < logs.length; j++) {
                            start = logs[j];
                            if (start.text.indexOf("Player gained ") == -1)
                                continue;
                            end = null;
                            for (var k = j + 1; k < logs.length; k++) {
                                if (logs[k].text.indexOf("Player lost ") == 0) {
                                    end = logs[k];
                                    j = k;
                                    break;
                                }
                            }
                            if (!end)
                                j = logs.length;
                            event.events.push({
                                start: start.t,
                                end: end ? end.t : this.result.t,
                            });
                            uptime+= (end ? end.t : this.result.t) - start.t;
                        }
                        event.uptime = Math.round(uptime / this.result.t * 100);
                        events.push(event);
                    }
                }

                // Trinkets
                var delta = 0;
                for (var i=0; i<this.trinkets.length; i++) {
                    var r = new RegExp(this.trinkets[i].title+"( \\\([0-9]+\\\))?\\\.");
                    logs = _.filter(this.result.log, l => l.type == 5 && l.text.match(r));
                    if (logs.length) {
                        uptime = 0;
                        event = _.clone(this.trinkets[i]);
                        event.events = [];
                        for (var j = 0; j < logs.length; j++) {
                            start = logs[j];
                            if (start.text.indexOf("Player gained ") == -1)
                                continue;
                            end = null;
                            for (var k = j + 1; k < logs.length; k++) {
                                if (logs[k].text.indexOf("Player lost ") == 0) {
                                    end = logs[k];
                                    j = k;
                                    break;
                                }
                            }
                            if (!end)
                                j = logs.length;
                            event.events.push({
                                start: start.t,
                                end: end ? end.t : this.result.t,
                            });
                            uptime+= (end ? end.t : this.result.t) - start.t;
                        }
                        event.uptime = Math.round(uptime / this.result.t * 100);
                        events.push(event);
                    }
                }

                // Mana gains
                var delta = 0;
                for (var i=0; i<this.mana_gains.length; i++) {
                    start = _.filter(this.result.log, function(a) { return a.text.indexOf(" mana from "+self.mana_gains[i].title) > 0; });
                    if (start.length) {
                        event = _.clone(this.mana_gains[i]);
                        event.events = [];
                        for (var j=0; j<start.length; j++) {
                            if (start[j].text.indexOf("Player gained ") == -1)
                                continue;
                            event.events.push({
                                start: start[j].t,
                                end: start[j].t+0.5,
                            });
                        }
                        events.push(event);
                    }
                }

                return events;
            },
        },

        methods: {
            timeStyle(time) {
                return {
                    left: (time / this.result.t * 100) + "%",
                }
            },

            barStyle(item, color) {
                return {
                    left: (item.start / this.result.t * 100) + "%",
                    right: (100 - (item.end / this.result.t * 100)) + "%",
                    background: color,
                };
            },

            formatTime(time) {
                return time+"s";
            },

        }
    }
</script>