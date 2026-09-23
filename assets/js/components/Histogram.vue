<template>
    <div class="histogram">
        <Bar v-if="chartData" :data="chartData" :options="chartOptions" />
        <div class="empty" v-else>No distribution data for this result.</div>
    </div>
</template>

<script>
    import { Bar } from "vue-chartjs";
    import {
        Chart as ChartJS,
        BarController,
        BarElement,
        CategoryScale,
        LinearScale,
    } from "chart.js";

    ChartJS.register(BarController, BarElement, CategoryScale, LinearScale);

    const BIN_SIZE = 50;

    export default {
        components: { Bar },

        props: ["data", "avg"],

        data() {
            return {
                chartOptions: {
                    responsive: true,
                    maintainAspectRatio: false,
                    animation: false,
                    color: "rgba(255,255,255,0.75)",
                    plugins: {
                        legend: {
                            display: false,
                        },
                        tooltip: {
                            enabled: false,
                        },
                    },
                    scales: {
                        x: {
                            offset: true,
                            title: {
                                display: true,
                                text: "DPS",
                            },
                            grid: {
                                color: "rgba(255,255,255,0.05)",
                            },
                            ticks: {
                                autoSkip: false,
                            },
                        },
                        y: {
                            beginAtZero: true,
                            title: {
                                display: true,
                                text: "Iterations",
                            },
                            grid: {
                                color: "rgba(255,255,255,0.05)",
                            },
                            ticks: {
                                maxTicksLimit: 20,
                            },
                        },
                    },
                },
            };
        },

        computed: {
            chartData() {
                if (!this.data || typeof this.data != "object")
                    return null;

                var keys = Object.keys(this.data)
                    .map(key => parseInt(key, 10))
                    .filter(key => !isNaN(key))
                    .sort((a, b) => a - b);

                if (!keys.length)
                    return null;

                var labels = [];
                var counts = [];
                var first = keys[0];
                var last = keys[keys.length - 1];

                for (var i = first; i <= last; i += BIN_SIZE) {
                    labels.push(i);
                    counts.push(Number(this.data[i]) || 0);
                }

                var avgBin = Math.floor(this.avg / BIN_SIZE) * BIN_SIZE;

                return {
                    labels: labels,
                    datasets: [{
                        data: counts,
                        backgroundColor: labels.map(bin => bin == avgBin ? "#4af" : "#08f"),
                        borderColor: labels.map(bin => bin == avgBin ? "#8cf" : "#05c"),
                        borderWidth: 1,
                        barPercentage: 1,
                        categoryPercentage: 1,
                    }],
                };
            },
        },
    }
</script>
